# 壊して☆ロボットアーム Readme
DX ライブラリと C++ 言語で作成した 2D 横スクロール破壊アクション

# 開発環境
Windows 11  
Visual Studio Community 2022

# 使用ライブラリ
[DX ライブラリ](https://dxlib.xsrv.jp/)  
[nlohmann-json](https://github.com/nlohmann/json)

# プロジェクト構成と起動方法
下記 DxLib ディレクトリ内に [DX ライブラリ Windows版 VisualStudio(C++)用](https://dxlib.xsrv.jp/DxLib/DxLib_VC3_24d.zip) を DownLoad して解凍後の ***プロジェクトに追加すべきファイル_VC用*** ディレクトリの内容を全てコピーします。
<pre>
.
├── DxLib(ライブラリ用ディレクトリ)
└── Game(ゲーム本体の Project)
    │
    ├── Game
    │   │
    │   ├── Res(ゲーム用リソースディレクトリ)
    │   │
    │   └── Source(ソースファイル)
    │       ├── enemybullet.cpp(敵の弾の挙動管理をするクラス)
    │       ├── framedata.cpp(アニメーションに関わる当たり判定等フレームを管理するクラス。敵の部分を担当)
    │       ├── framedata.h
    │       ├── mapdata.cpp(Tiledで作ったマップを管理するクラス。エフェクトなど担当)
    │       ├── mapdata.h
    │       ├── motiondata.cpp(フレームデータに渡すアニメーションを管理するクラス。敵の部分を担当)
    │       ├── motiondata.h
    │       ├── mymath.cpp(よく使う計算関数が入っているクラス。一部担当)
    │       ├── mymath.h
    │       ├── scenegamelogo.cpp(ロゴを表示し、フェードアウトさせてタイトルにつなげるクラス)
    │       ├── scenegamelogo.h
    │       ├── scenegamemain.cpp(ゲームのメインのクラス。敵の部分を担当)
    │       ├── scenegamemain.h
    │       ├── scenegamesystem.cpp(当たり判定のクラス。一部担当)
    │       ├── scenegametitle.cpp(タイトルクラス)
    │       ├── scenegametitle.h
    │       ├── scenemaineffect.cpp(敵死亡時等、エフェクトを管理するクラス)
    │       ├── scenemainenemy.cpp(敵の管理をするクラス)
    │       ├── scenemainobject.cpp(ステージ上においてある柱や自動販売機などのオブジェクト類を管理するクラス)
    │       ├── ui.cpp(腕のレベルやタイマーなどのUIを管理するクラス)
    │       ├── ui.h
    │
    └── Game.sln(こちらを起動して下さい)
</pre>