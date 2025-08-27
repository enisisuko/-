# === 中文版 README ===
cat > README.md << 'MD'
<!-- lang switch -->
<p align="right">🌐 Language: <b>简体中文</b> · <a href="./README.ja.md">日本語</a></p>

<!-- hero -->
<h1 align="center">光灵传说 · Lumen Saga</h1>
<p align="center"><em>当文明褪去，仍需有人将光点燃。</em></p>
<p align="center">
  <a href="../../releases"><img alt="Releases" src="https://img.shields.io/badge/download-releases-3b82f6"></a>
  <a href="../../issues"><img alt="Issues" src="https://img.shields.io/github/issues/enisisuko/-"></a>
  <a href="../../commits"><img alt="Last Commit" src="https://img.shields.io/github/last-commit/enisisuko/-"></a>
  <a href="../../stargazers"><img alt="Stars" src="https://img.shields.io/github/stars/enisisuko/-?style=social"></a>
</p>

<p align="center">
  <a href="#-概览">概览</a> ·
  <a href="#-核心玩法与美术表现">玩法</a> ·
  <a href="#-世界观与叙事底色">世界观</a> ·
  <a href="#-操作--输入映射">操作</a> ·
  <a href="#-系统设计蓝图">系统</a> ·
  <a href="#-快速开始">开始</a> ·
  <a href="#-Roadmap">Roadmap</a> ·
  <a href="#-贡献">贡献</a>
</p>

---

## ✨ 概览
**一句话**：一款“建造 × 招募 × 职业进阶”的波次防卫游戏。你在焦土上修筑圣坛、招募光灵、规划经济与职业曲线，守护圣女与最后的净土。

- **平台**：Windows（DirectX 渲染）；计划适配主机后端（OpenGL 4.5 渲染路径已抽象）
- **状态**：持续开发 / 不断打磨
- **游玩**：前往 **[Releases](../../releases)** 下载最新构建
- **问题与建议**：在 **[Issues](../../issues)** 留言，或参与 **[Projects](../../projects)** 讨论

---

## 🎮 核心玩法与美术表现
- **四类建筑·四条增长曲线**
  - **金币建筑**：波次结算金币，拉动“宏观经济”。
  - **光灵建筑**：提供人口与战斗基数。
  - **职业建筑**：转化为 _星空魔法师 / 森林战士_；升级升阶，**满级诞生唯一英雄单位**。
  - **圣女祭坛**：全队增幅中枢；满级化作**至高圣女**，法阵范围暴涨并持续伤害敌方。
- **编队与压强**：小兵 / 弓手 / 冲锋手 / 重盾 /唤魔者 /隐身杀手 /BOSS的**节拍推进**，迫使你在“经济—军备—祭坛”间做取舍。
- **轻量而丰富的表现**：HUD 等比绘制、拖影/抖屏/飘字、击退震击、能量涟漪与光晕，细腻而不过载。

> 设计哲学：**数值是秩序，节奏是叙事**——一次漂亮的波次调度，本身就是篇章。

---

## 🜂 世界观与叙事底色
黑暗涨潮后，文明在边界逐块退却。**金币**维系秩序，**光灵**是燃料与火种，**职业**是知识的形态，而**祭坛**放大信念。  
当你调度建筑与人口的节奏，法阵边界便随之呼吸——**希望被你亲手编排**。

---

## ⌨️ 操作 · 输入映射
- **移动**：`W A S D`  
- **选择切换**：`↑ / ↓`（或手柄十字键上下）  
- **确认 / 交互**：`Space`（或手柄右扳机）  

> 计划中的完整手柄映射：左摇杆 ↔ WASD，十字键 ↔ 方向键，右扳机 ↔ Space。

---

## 🧩 系统设计蓝图
```
┌────────── Economy ──────────┐     ┌────── Combat ──────┐
│  Gold Bldg  →  Coins  ─┐     │     │  Units & AI        │
│  Lumen Bldg →  Population ─┬─┼──►  │  Waves / Formations │
│  Job Bldg   →  Classes   ─┘  │     │  Boss Phases        │
│  Altar      →  Global Buffs  │     └────────┬───────────┘
└─────────────┬───────────────┘                │
              ▼                                ▼
         Hero Emergence                  Visual Feedback
      (Unique, high impact)            (Shake/Trail/Glow)

```
进阶与稀缺：职业升阶与祭坛加成存在瓶颈与唯一性，鼓励差异化解。

波次节拍：建设→战斗→复盘→再建设；短期容错与长期曲线并存。

资源流：金币、人口、职业位与祭坛加成交错，形成可被“雕刻”的策略空间。

## ⚙️ 快速开始
需要：Visual Studio 2022（含“使用 C++ 的桌面开发”组件）、Windows 10/11 SDK

```
git clone https://github.com/enisisuko/-.git
cd -
# 打开解决方案用 VS 构建（建议 Release）
# 或使用命令行： msbuild Game.sln /p:Configuration=Release
资源放置建议：

大体积纹理/音频请使用 Git LFS（如 .tga）；

不要将任何受限/商业 SDK 文件纳入版本控制（例如专有主机 SDK）1.
```
## 🗺️ Roadmap

 英雄级单位专属天赋与事件

 手柄全映射 + 震动反馈

 OpenGL 4.5 渲染路径完善（为主机移植铺路）

 关卡 Modifier 与更细难度曲线

 自动化构建与发布流程（CI/CD）

跟踪开发：看 Projects 与 Issues。

## 🤝 贡献
欢迎提交 PR / Issue。发起 PR 前请先阅读 贡献约定（代码风格、提交信息语义化、分支模型等）——见 Wiki。

## 📝 许可
本仓库以个人项目形式公开，未经书面许可禁止商业用途。最终许可证与商业条款将于 Releases 与 LICENSE 公告。

## 🔗 快捷链接
下载发布：<../../releases>

问题反馈：<../../issues>

开发文档：<../../wiki>

项目面板：<../../projects>

<p align="center"> <sub>如果你愿意，也请点一颗小星星 ⭐。你的注视，就是这片净土扩张的半径。</sub> </p>
=== 日文版 README ===
cat > README.ja.md << 'MD'

<!-- lang switch --> <p align="right">🌐 言語: <a href="./README.md">简体中文</a> · <b>日本語</b></p> <!-- hero --> <h1 align="center">光霊伝説 · Lumen Saga</h1> <p align="center"><em>文明が退いたとしても、光を灯す者がいる。</em></p> <p align="center"> <a href="../../releases"><img alt="Releases" src="https://img.shields.io/badge/download-releases-3b82f6"></a> <a href="../../issues"><img alt="Issues" src="https://img.shields.io/github/issues/enisisuko/-"></a> <a href="../../commits"><img alt="Last Commit" src="https://img.shields.io/github/last-commit/enisisuko/-"></a> <a href="../../stargazers"><img alt="Stars" src="https://img.shields.io/github/stars/enisisuko/-?style=social"></a> </p> <p align="center"> <a href="#-概要">概要</a> · <a href="#-コアゲームプレイと表現">ゲーム性</a> · <a href="#-世界観とナラティブ">世界観</a> · <a href="#-操作--入力マッピング">操作</a> · <a href="#-システム設計">システム</a> · <a href="#-クイックスタート">開始</a> · <a href="#-roadmap">Roadmap</a> · <a href="#-コントリビュート">貢献</a> </p>
✨ 概要
一言で：建設 × 募兵 × 職業進化による「ウェーブ防衛」ゲーム。焦土で祭壇を築き、光霊を招き、経済と職業曲線を編成して、聖女と最後の浄土を護ります。

プラットフォーム：Windows（DirectX レンダリング）。将来的にコンソール後段へ（OpenGL 4.5 パスは抽象化済み）

ステータス：継続開発中

プレイ：Releases から最新ビルドを入手

要望/不具合：Issues または Projects へ

🎮 コアゲームプレイと表現
4 種の建物・4 つの成長曲線

ゴールド建物：ウェーブ終了時にコインを精算し、経済を駆動。

光霊建物：人口と戦闘基盤を供給。

職業建物：星空魔導師 / 森林戦士 に転化。アップグレードで階位上昇、最終段で唯一の英雄ユニットが誕生。

聖女祭壇：全体バフの中枢。最終段では至高の聖女となり、陣域が大きく拡張し敵へ持続ダメージ。

編成と圧力：歩兵／弓兵／突撃／重盾の拍動的前進が、経済・軍備・祭壇の取捨選択を迫る。

軽量かつ豊かな表現：HUD 等比描画、残像／カメラシェイク／フローティングテキスト、ノックバック、光輪・波紋などを過不足なく配置。

デザイン哲学：数値は秩序、リズムは物語。美しいウェーブ運用そのものが章となる。

🜂 世界観とナラティブ
暗黒が満ち、文明は縁から後退した。コインは秩序を保ち、光霊は燃料であり火種。職業は知のかたち、そして祭壇は信の増幅器。
建設と人口のリズムを編むとき、陣域は呼吸し、希望はあなたの手で編曲される。

⌨️ 操作 · 入力マッピング
移動：W A S D

選択切替：↑ / ↓（または十字キー上下）

決定 / インタラクト：Space（または右トリガー）

予定：左スティック ↔ WASD、十字キー ↔ 方向キー、右トリガー ↔ Space。

🧩 システム設計
```
┌────────── Economy ──────────┐     ┌────── Combat ──────┐
│ Gold → Coin Flow ─┐             │     │ Units / AI          │
│ Lumen→ Population ─┬─┬──────────┼──►  │ Waves / Formations   │
│ Jobs → Classes   ─┘ │          │     │ Boss Phases          │
│ Altar→ Global Buffs  │          │     └────────┬────────────┘
└───────────┬─────────┘          │                   │
            ▼                    ▼                   ▼
      Hero Emergence       Economy Tuning      Visual Feedback
```
希少性とボトルネック：職業進化と祭壇バフには唯一性と臨界があり、分岐解を促す。

ウェーブの律動：建設→戦闘→内省→再建設。短期の猶予と長期曲線が併存。

資源流：コイン／人口／職枠／祭壇バフが交差し、彫刻可能な戦略空間を形成。

⚙️ クイックスタート
必要：Visual Studio 2022（C++デスクトップ開発）、Windows 10/11 SDK

```
git clone https://github.com/enisisuko/-.git
cd -
# ソリューションを開いてビルド（Release 推奨）
# もしくは： msbuild Game.sln /p:Configuration=Release
アセット指針：

大容量のテクスチャ/オーディオには Git LFS を推奨（.tga 等）

制限付き/商用 SDK はバージョン管理に含めないでください1.
```
🗺️ Roadmap
 本編 3 章 & 段階的ボス

 英雄ユニット専用の特性とイベント

 パッド完全対応 + 振動

 OpenGL 4.5 レンダリングパス拡充（コンソール移植に備える）

 ウェーブ Modifiers と細かな難易度曲線

 中/日/英 ローカライズ

 CI/CD による自動ビルドと配布

🤝 コントリビュート
PR / Issue を歓迎します。PR 前に 貢献ガイド（コード規約、コミットメッセージ、ブランチ運用）をご一読ください——Wiki を参照。

📝 ライセンス
本リポジトリは個人プロジェクトとして公開中であり、商用利用は禁止です。最終的なライセンスは Releases および LICENSE にて告知します。

🔗 クイックリンク
ダウンロード：<../../releases>

不具合・提案：<../../issues>

ドキュメント：<../../wiki>

プロジェクト：<../../projects>

<p align="center"> <sub>もし気に入っていただけたら ⭐ を。あなたの視線が、浄土の半径を広げる。</sub> </p>
echo "✅ 已生成 README.md / README.ja.md"



---

素素直接把上面整段贴进 **Git Bash** 执行就好～  
如果你需要 **PowerShell 版本**（`Set-Content` + here-string）或想自动加上 **GitHub Pages 语言跳转页**，跟菜娘说一声，我立刻给你补上可执行脚本哟 (づ˘◡˘)づ ♡
Footnotes
出于合规与安全考虑，任何受限/商业 SDK（如某些主机平台 SDK）不得随仓库分发。
MD ↩ ↩2
