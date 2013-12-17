/*
** Taiga
** Copyright (C) 2010-2013, Eren Okka
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TAIGA_TAIGA_TAIGA_H
#define TAIGA_TAIGA_TAIGA_H

#include "update.h"
#include "win/win_main.h"

#define APP_NAME    L"Taiga"
#define APP_TITLE   L"Taiga 1.1a"
#define APP_VERSION L"1.1 alpha"
#define APP_BUILD   L"2013-11-19"

#ifndef PORTABLE
#define PORTABLE
#endif

namespace taiga {

enum PlayStatus {
  kPlayStatusStopped,
  kPlayStatusPlaying,
  kPlayStatusUpdated
};

enum TipType {
  kTipTypeDefault,
  kTipTypeNowPlaying,
  kTipTypeSearch,
  kTipTypeTorrent,
  kTipTypeUpdateFailed
};

class App : public win::App {
public:
  App();
  ~App();

  BOOL InitInstance();
  void Uninitialize();

  void LoadData();

  int current_tip_type, play_status;
  bool logged_in;
  int ticker_media, ticker_memory, ticker_new_episodes, ticker_queue;

  class Updater : public UpdateHelper {
  public:
    void OnCheck();
    void OnCRCCheck(const std::wstring& path, std::wstring& crc);
    void OnDone();
    void OnProgress(int file_index);
    bool OnRestartApp();
    void OnRunActions();
  } Updater;
};

}  // namespace taiga

extern taiga::App Taiga;

#endif  // TAIGA_TAIGA_TAIGA_H