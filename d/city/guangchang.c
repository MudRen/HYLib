// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "����㳡");
  set ("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ�
�е��������������������������������ݡ�������һ�ô��������̸�
��ڣ��ݴ�����ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�
������ (dong)�� ����Կ������������Ը��ص�������������������������
�У�һ�ɷ������󡣶������Ÿ�Ȫ�֡�������ͨ���š�
LONG );

  set("objects", ([ /* sizeof() == 4 */
    
"/clone/misc/dache" : 1 ,
  __DIR__"npc/liumangtou" : 1,
  __DIR__"npc/xunbu" : 3,
  "/clone/topten/topten" : 1,
  __DIR__"npc/liumang" : 4,
  "quest/shenshu/man":1,
]));
  set("outdoors", "city");
  set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�
",
]));
  set("exits", ([ /* sizeof() == 5 */
  "up" : "/d/pingan/pinganmen",
  "north" : __DIR__"beidajie1",
  "east" : __DIR__"dongdajie1",
  "south" : __DIR__"nandajie1",
  "down"	: __DIR__"lajichang",
  //"west" : __DIR__"xidajie1",
"west"  : __DIR__"tongsiqiao",
]));
  set("no_sleep_room", 1);

  setup();
}

void init()
{
        add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="up")
	{
		
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}