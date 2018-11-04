// Room: xiaolu5.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "青石台阶");
	set("long", @LONG
这是由青石砌成的台阶，方方正正，看起来颇为考究，大青石一块一块直
铺到大厅，台阶两边还做了栏杆。台阶四周长着一些野草，头顶有一些不知名
的小鸟在跳来跳去。
LONG
	);
	set("exits", ([ 
	    "eastdown" : __DIR__"xiaolu4",
	    "northup" : __DIR__"wljmen",
        ]));

        set("outdoors", "大理");

	setup();
        replace_program(ROOM);
}
