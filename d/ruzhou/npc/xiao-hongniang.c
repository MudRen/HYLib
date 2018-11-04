//������(tubaozi)�����㣺woodman@pub.wx.jsinfo.net

// Npc: /d/ruzhou/npc/xiao-hongniang.c С����  ר���������֪
// by llm 99/06

#include <ansi.h>

inherit NPC;
int ask_marry();
int ask_guest();

void create()
{
	set_name("С����", ({ "xiao hongniang", "hongniang" }));
   set("long","����һ�����úܺÿ���С�����������ֱֱ���ϵ�С���ӣ��Ե������ؿɰ��ˡ�\n");
   set("gender", "Ů��");
   set("age", 16);
   set_skill("unarmed", 20);
   set_skill("dodge", 20);
   set_skill("parry", 20);
   set_temp("apply/attack", 30);
   set_temp("apply/defense", 30);
   set_temp("apply/damage", 5);
   set("combat_exp", 3000);
   set("shen_type", 1);
   set("inquiry", ([
		"���"    : (: ask_marry :),
      "����": (: ask_marry :),
      "�����֪"    : (: ask_marry :),
      "�������֪��"    : (: ask_marry :),
      "����"    : (: ask_marry :),
      "���"    : (: ask_guest :),
      "����"    : (: ask_guest :),
   ]));
   setup();

}
void init()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	::init();
	if( !ob || environment(ob) != environment() ) return;
  	say("С����Ц������˵������������ׯ����ϲ�£��ɵ�Ҫ֪��һЩ��࣬�������֪���Ļ����������ң���\n");
}

int ask_guest()
{
	object me;
	me = this_object();

	if (me->is_busy())
		return notify_fail("С����˵��������æ����ٺ���˵���ɣ���\n");
	if( this_object()->is_fighting()||me->is_fighting() )
		return notify_fail("С����˵����������û���򣡡�\n");
	if( !living(this_object()) )
		return notify_fail("�㻹������취��С������Ѱɡ�\n");
	if ( (string)me->query("gender") == "����")
		return notify_fail("С�������������ض��Ӷ�Цʹ�ˣ�����Ҫ��飿��Ҫ��ͣ���������������\n");
	if (((int)me->query("age") < 18) && (me->query("gender") == "����")
		||((int)me->query("age") < 16) && (me->query("gender") == "Ů��"))
		return notify_fail("С��������һЦ����������Ҳ��󣬾���������ˣ����еģ���\n");
	if( (string)me->query("class")=="bonze"||(string)me->query("jobname")=="taoist" )
		return notify_fail("С��������һЦ��������ɱ����ҿ���Ц����������ô�ܽ���أ���\n");
   if(me->query("couple/have_couple"))
   	return notify_fail("С������������������Ѿ������������ô����......��\n");
	write( "С����˵����ֻ�е�ý�����ｻ��Ǯ�󣬾Ϳ�����ý�Ű����ϲȵ������ˡ���\n");
	return 1;
}

int ask_marry()
{
   object ob;
   if(this_player()->query_temp("marry-book"))
		return notify_fail("С������Щ�������ˣ������������ô���������ող��Ǹ�����һ������\n");
   message_vision("С������ͷ���ó�һ���������֪������$N��˵������������һ���ӵĴ��£�\n"
   "��һ��Ҫ��ϸ��������Ҫ�ڰ���ʱ������Ū��ǮҲ���ˣ���Ҳû��ɡ���\n",this_player());
   ob=new(__DIR__"obj/marry-book");
   ob->move(this_player());
	this_player()->add_temp("marry-book",1);
	return 1;
}
