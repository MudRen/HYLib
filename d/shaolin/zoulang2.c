// Room: /d/shaolin/zoulang2.c
// Date: YZC 96/01/19

inherit ROOM;

string look_picture();

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。房顶一侧支在南面的高墙上，另一侧凌空
架在几根细细的石柱上。彩梁画栋，连顶棚也用彩漆绘满了各种
飞天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。南
边墙上也画着一幅画(picture)。北望可以观赏僧众们练武的场面。
LONG );
	set("exits", ([
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"houdian",
		"north" : __DIR__"wuchang1",
	]));
	set("item_desc",([
		"picture"		:	(: look_picture :),
	]));
	set("no_clean_up", 0);
	setup();
}


string look_picture()
{
	return
	"\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※+----------------------+※※※※※※※\n"
	"    ※※※※※※※|::::        **     :: |※※※※※※※\n"
	"    ※※※※※※※|::        ***       : |※※※※※※※\n"
	"    ※※※※※※※|:        ***｜*  ** : |※※※※※※※\n"
	"    ※※※※※※※|:          *｜*,*     |※※※※※※※\n"
	"    ※※※※※※※|  *** * *   ｜/* **   |※※※※※※※\n"
	"    ※※※※※※※|   *＼'** * ｜        |※※※　※※※\n"
	"    ※※※※※※※|   ***＼**  ｜        |※※　修　※※\n"
	"    ※※※※※※※|     * *＼ *┃  ***   |※※　身　※※\n"
	"    ※※※※※※※|#         ＼┃**,*    |※※　如　※※\n"
	"    ※※※※※※※|:           ┃／      |※※　竹　※※\n"
	"    ※※※※※※※|:           ┃        |※※※　※※※\n"
	"    ※※※※※※※|.                 ..@ |※※※※※※※\n"
	"    ※※※※※※※+----------------------+※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}

