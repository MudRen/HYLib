inherit ROOM;
void create()
{
	set("short", "��Ԫ��");
	set("long", @LONG
����һ�������˽�����ʮ��а�ɸ��ֵ���������ʮ��֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"southdown":"/d/city/guangchang",
		"up":__DIR__"a2",
	]));
		set("objects", ([
			__DIR__"jiumozhi": 1,
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
add_action("do_dazuo","get");
if(userp(this_player()) && (!this_player()->query_temp("for_ok")))
{call_out("away",900);
message_vision("��ֻ��һ���ӵ�ʱ������������а�ɸ��֡����۳ɹ����һ���Ӻ��㽫�Զ����ͻع㳡���롣\n",this_player());
this_player()->set_temp("for_ok",1);
}
}

int away()
{
object me;
me= this_player();
if (!me) return notify_fail("���Ѿ������ˣ�\n");
message_vision("�ѹ���һ���ӵ�ʱ�䣬$N�����͵��㳡���롣\n",me);
me->move("/d/city/guangchang");
message_vision("$N������ͻȻ�����ڹ㳡���롣\n",me);
this_player()->set_temp("for_ok",0);
return 1;
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"���ﲻ�������ָ�\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="up" && ob=present("jiumo zhi", this_object()))
return notify_fail("����Ӳ������\n");
if (this_player()->query("shen") > 0&& dir=="up" ) 
return notify_fail("���ﲻ��ӭ�������£�\n");
return 1;
}
