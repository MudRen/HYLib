inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ�������˽�����ʮ�����ɸ��ֵ�¥������ʮ��֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"northdown" : "/d/city/guangchang",
		"up":__DIR__"b2",
	]));
		set("objects", ([
			__DIR__"miejue": 1,
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
if(userp(this_player()) && (!this_player()->query_temp("for_okok")))
{call_out("awayaway",900);
message_vision("��ֻ��һ���ӵ�ʱ���������������ɸ��֡����۳ɹ����һ���Ӻ��㽫�Զ����ͻع㳡���롣\n",this_player());
this_player()->set_temp("for_okok",1);
}
}

int awayaway()
{
object me;
if (!me) return notify_fail("���Ѿ������ˣ�\n");
me= this_player();
message_vision("�ѹ���һ���ӵ�ʱ�䣬$N�����͵��㳡���롣\n",me);
me->move("/d/city/guangchang");
message_vision("$N������ͻȻ�����ڹ㳡���롣\n",me);
this_player()->set_temp("for_okok",0);
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
dir=="up" && ob=present("miejue shitai", this_object()))
return notify_fail( 
"����Ӳ������\n");
if (me->query("shen")<0&&dir=="up")
return notify_fail("���ﲻ��ӭа�����£�\n");

return 1;
}
