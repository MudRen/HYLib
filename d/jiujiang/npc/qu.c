
inherit NPC;
#include <ansi.h>
int do_cha(string arg);
mapping *name=({
(["name":"��","id":"zhao",]),(["name":"Ǯ","id":"qian",]),(["name":"��","id":"sun",]),
(["name":"��","id":"zhou",]),(["name":"��","id":"wu",]),(["name":"֣","id":"zheng",]),
(["name":"��","id":"li",]),(["name":"��","id":"wang",]),(["name":"��","id":"liu",]),
(["name":"���","id":"zhuge",]),(["name":"��","id":"ding",]),(["name":"��","id":"jin",]),
});
void create()
{
   mapping newname;
   newname=name[random(sizeof(name))];
      set_name(newname["name"]+"�ϰ�",({ newname["id"]}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "����[���Ǿ�¥]���ϰ塣\n");
       
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_neili",500);
   set("kee",800);
   set("max_jing",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
  
   setup();
   //carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
		add_action("do_cha","chazhang");
}
int do_cha(string arg)
{
	object me,ob,money;int exp,pot,sil;
	me=this_player();
	if(!arg||!present(arg,environment(me)))
		return notify_fail("��Ҫ��˭���ʣ�\n");
	if(!me->query_temp("chazhang_job/4"))
		return notify_fail("��û�������ʵ�Ȩ����\n");
	me->set_temp("busy_time",time());
	exp=me->query("max_pot")/3+random(10);
        pot=me->query("max_pot")/4;
	sil=pot/2;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot"))
	me->set("potential",me->query("max_pot"));
	money=new("obj/money/silver");
	money->set_amount(sil);
	money->move(me);
	me->delete_temp("chazhang_job");
	me->delete_temp("dtsl_job");
	tell_object(me,"������ж��У���õ��ˣ�"
               +""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ"
               +""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��"
               +""HIW""+chinese_number(sil)+""NOR""+"������\n");
	return 1;
}
