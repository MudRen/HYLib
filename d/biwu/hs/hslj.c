#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"��ɽ֮��"NOR);
        set("long", @LONG
   �����е�һ��ʥ�ء�������ԭ����ڴ˴����䶨λ�Ծ������µ�һ,
����ÿ��һ��ʱ�䣬�ڴ˾ͻ����һ�λ�ɽ�۽����Կ��齭�����������
���ڰ�����һ��ʯͷ���������һЩ�˵����֣�
[33m
                       ��а ������
                       �ϵ� ��ؤ��
                        ����ͨ              
[36m
              �������ս��ԭ������л�ɽ�۽���(lunjian)
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/huashan/lianhua",
]));
       
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_get",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","lunjian");
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","respirate");
        add_action("do_quit2","tuna"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}
int  do_levelup(string arg)
{
	object me, ob;
	object fight;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if (me->is_fighting()) 
        return notify_fail("�����ڻ�ɽ�۽���!\n");
	if( me->is_busy() )
		return notify_fail("����æ����! \n");
        if (!wizardp(me) && !me->query("guard/flag"))
	return notify_fail("��Ľ������黹������û���ʸ�ɽ�۽���\n");
        if (!wizardp(me) && me->query("combat_exp")< 5000000)
	return notify_fail("���������������û���ʸ�ɽ�۽���\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
	return notify_fail("�����ѧ̫�࣬��ɽ�۽�ֻ�����ܴ���һ�����ɵ�����μӣ�\n");
	if(!wizardp(me) && me->query("guard/ok"))
	return notify_fail("���Ѿ�ͨ���˻�ɽ�۽��ˣ�\n");

	if(environment(me)->query("alrd")
	 && !me->query_temp("hslj/1"))
	return notify_fail("���ڻ�������ɽ�۽���ʱ�䣬���Ѿ���ʼ�ˣ�\n");
environment(me)->set("alrd",1);
if (!me->query_temp("hsljn"))
{
environment(me)->set("alrd",1);
message("channel:chat", HIG"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս��ԭ���!"NOR"\n", users());
me->set_temp("hsljn",1);
}
me->start_busy(2);

if (!me->query_temp("hslj"))
{
fight=new(__DIR__"huang");
fight->move(environment(me));
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
fight->kill_ob(me);
message("channel:chat", CYN"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս��а��ҩʦ!"NOR"\n", users());
}
else
if (me->query_temp("hslj/1")
&& !me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{
fight=new(__DIR__"hong");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", YEL"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս��ؤ���߹�!"NOR"\n", users());
}
else
if (me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{

fight=new(__DIR__"yideng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIY"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս�ϵ�һ��!"NOR"\n", users());
}
else
if (me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5")
)
{
fight=new(__DIR__"ouyangfeng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIR"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս����ŷ����!"NOR"\n", users());
}
else
if (!me->query_temp("hslj/5"))
{
fight=new(__DIR__"wang");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIB"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮����ս����ͨ������!"NOR"\n", users());
}
else 
{
me->set("guard/ok",1);
me->save();
message("channel:chat", HIW"����ɽ�۽�����˵"+me->name() + "�ڻ�ɽ֮��ͨ������ԭ����Ŀ���!"NOR"\n", users());
}
return 1;
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"�����ĵĻ�ɽ�۽��ɣ�\n");
        return 1;
	}

	if(arg=="all") {
        write(this_player()->query("name")+"�����ĵĻ�ɽ�۽��ɣ�\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"�����ĵĻ�ɽ�۽��ɣ�\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"�����ĵĻ�ɽ�۽��ɣ�\n");
        return 1;
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
       if (  me->is_fighting() )
        return notify_fail("�㲻���ڱ�����\n");
	
        me->delete_temp("hsljn");
	return ::valid_leave(me, dir);

}

