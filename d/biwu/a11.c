inherit ROOM;
void create()
{
	set("short", "��Ԫ����");
	set("long", @LONG
������������߲㣬������Ÿ�ħ�ȣ������طų���â��������ǳ������Ļ���
�����������(yaoche)��
    ����û�г��ڣ���ֻ�ܵȴ���һ���Ӻ��Զ��ͻع㳡��
LONG );
       set("no_sleep_room",1);
     set("no_clean_up", 0);
	set("objects", ([
			"/d/biwu/champion1": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_yao","yaoche");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
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
int do_yao()
{
	object *inv,kicker;
	int sizeinv,n,tt;

object me;

me = this_player();
if(!me->query("marks/mengzhu"))
		return notify_fail("��û�г�����Ȩ�ޡ�\n");
   if (!me->query_temp("che"))
		return notify_fail("��ղ�û�г˳������\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
	me->set_temp("che",0);
 message_vision("$N�߳���Ԫ���������˸ղ���ʱ���������Ҵ�ææ����ȥ�ˡ�\n",me);
me->move("/d/city/majiu");
message_vision("$N�ֻص���ԭ����ʱ���Ǽ���ǡ�\n",me);

return 1;
}/*
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="down")
this_player()->set_temp("for_ok",0);
return 1;
}*/
