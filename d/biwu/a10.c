inherit ROOM;
void create()
{
	set("short", "��Ԫ����ʮ��");
	set("long", @LONG
����һ�������˽�����ʮ��а�ɸ��ֵ���������ʮ��֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"a9",
		"up":__DIR__"a11",
	]));
		set("objects", ([
			__DIR__"ouyangfeng": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","fight");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");}

int do_dazuo()
{
   object me;
   me = this_player();
tell_object(me,"���ﲻ�������ָ�\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
int sizeinv;
if( userp(me) &&
dir=="up" && ob=present("ouyang feng", this_object()))
return notify_fail( 
"����Ӳ������\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
return 1;
}

