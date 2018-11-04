
inherit NPC;
#include <ansi.h>

string give_job();
int do_ok(string arg);
void create()
{
   set_name("����ɽ",({ "xiang yushan","xiang","yushan" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����[�����]������ɽ��\n");
       
   set("combat_exp", 80000);
   set("str", 10);
   set("per", 25);
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_neili",200);
   set_skill("force",30);
   set("attitude", "peaceful");
   set("inquiry",([
	   "�����˿�":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	me=this_player();
	if(me->query("gender")=="Ů��")
		return "���ֹ���Ů���������ģ�\n";
	if(me->query_temp("fanmai_job"))
		return "�����»���һ��һ�����ɣ�\n";
	if(time()-me->query("task_time")<=130+random(5))
		return "����ЪЪ�ɣ�\n";
	me->set_temp("fanmai_job",1);
	return "�ð�,��Ȼ"+RANK_D->query_respect(me)+"Ը�⣬�����һ��Ư���Ĺ�����(jiaochai)����\n���Ҳ��������ģ�\n";
}

int do_ok(string arg)
{
	object me,ob,money;
	int exp,pot,sil,famous;int i,per;
	me=this_player();i=0;
	if(!arg) return notify_fail("����ʲô�����\n");
	if(!me->query_temp("fanmai_job")&&me->query("vocation")!="�˷���")
		return notify_fail("�⻰�Ӻ�˵��\n");
	if(!objectp(ob=present(arg,environment(me))))
		return notify_fail("����û������ˣ�\n");
	if(ob->query("gender")=="����")
		return notify_fail("���˿ɲ�Ҫ��\n");

	if(userp(ob))
		return notify_fail("��ҿɲ�Ҫ��\n");

    if(ob->query("per")<=25&&me->query("vocation")!="�˷���")
		return notify_fail("����˵���ɫ�����ҵ�Ҫ���㻹�ǻ�һ���ɣ�\n");
	per=ob->query("per");
	i=per;

	exp=random(1888);
    while(exp>10)
	{ exp=exp/10; i++;}
	exp=exp+i*10;
	pot=exp*2/3;
	sil=exp/3;
	per=ob->query("per");
    tell_object(environment(me),"����ɽ��ͷ�������ˣ�����λ�������ȥ��\n");
	tell_object(environment(me),"���̳���һ���ˣ���"+ob->name()+"���ȥ�ˡ�\n");
	destruct(ob);
	if(me->query_temp("fanmai_job"))
	{
        sil=random(888)+(i*20);
	me->add("deposit",sil);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->start_busy(8);
	me->delete_temp("fanmai_job");
	me->set("task_time",time());
	tell_object(me,"������ж�����õ���"+
                ""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ"+
                ""HIW""+chinese_number(pot)+""NOR""+"��Ǳ��"+
                "����ɽ��������"+""HIW""+chinese_number(sil)+""NOR""+"��ͭǮ��\n");
        tell_object(me,"��Ǯׯ�Ĵ�������ˣ�\n");
	tell_object(me,"���ڷ����˿ڣ���Ľ������������ˣ�\n");
	}
	else
	{
		tell_object(me,"����ɽЦ�����ã������Ŭ���ɣ�\n");
	}
	return 1;
}
