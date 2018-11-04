// Room: /d/chengdu/chunxilu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "春熙路口");
	set("long", @LONG
这里是成都府最繁华的地带——春熙路，并不宽的街道两旁，店铺
林立汉白玉砌的路面几乎能照出人影。路上的行人摩肩接踵，都在为各
自的生计奔波着。一派繁荣，富庶的景象。
    不远处的公告栏(sign)站着两名衣甲鲜明的卫兵。不时警惕的看着
你。
LONG);
	set("outdoors", "chengdu");
	set("objects", ([
		__DIR__"npc/weibing" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"chunxilu1",
		"north" : __DIR__"dongjie1",
	]));
	set("item_desc", ([ 
		"sign" : "成都大府，严禁乱来，否则弄凶！\n",
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
       
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;

	if( userp(me) && dir == "south" && ob=present("wei bing",this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) &&
				(int)(inv[i]->query("equipped")))
				return notify_fail( ob->name()+"向你喝道：你娃想造反唆，搞快放下手持兵器才能进去！\n"); 
		}
	}
	return 1;
}

