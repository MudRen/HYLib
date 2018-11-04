
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","庐山");
  set ("long", @LONG
 庐山雄奇秀拔，云雾缭绕，山中多飞泉瀑布和奇洞怪石，名胜古迹遍布，
夏天气候凉爽宜人，是我国著名的旅游风景区和避暑疗养胜地，于1996
年被列入“世界自然与文化遗产名录”。古人云“匡庐奇秀甲天下”，自司
马迁将庐山载入《史记》后，历代诗人墨客相继慕名而来，陶渊明、谢
灵运、李白、白居易、苏轼、王安石、陆游、徐志摩 、郭沫若等1500
余位诗人相继登山，留下了许多珍贵的名篇佳作。苏轼所写的“横看成
岭侧成峰，远近高低各不同。不识庐山真面目，只缘身在此山中”形象
描绘了庐山的景色，成为千百年来脍炙人口的名篇。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu1",
 "south":__DIR__"shanlu3",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

