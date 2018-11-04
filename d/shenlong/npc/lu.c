//lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("½����", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("title", "�����̾�ʦ");
	set("nickname",HIC "�������" NOR);
	set("long", "����ͥ����,������Բ,��ò��ΪӢ��.\nȻ���������,ǡ����̼����ɱ��֮��һ��.\n" );
	set("gender", "����");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
        set("qi",1500);
	set("max_jing",500);
        set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("literate", 100);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("hand", 70);
	set_skill("staff", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("hamagong", 70);
	set_skill("yixingbu", 70);
	set_skill("shenlong-quanfa", 70);
	set_skill("shenlong-xinfa", 70);
	set_skill("shedao-qigong", 70);
	set_skill("shexing-diaoshou", 70);
	set_skill("tianshan-zhang", 70);

	map_skill("dodge", "yixingbu");
	map_skill("force", "hamagong");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("parry", "shexing-diaoshou");
	map_skill("staff", "tianshan-zhang");

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 60);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
add_action("do_join","join");
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "½����˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "½������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "½������$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
  if ( ob->query_skill("bibo-shengong",1)
	|| ob->query_skill("hamagong",1)
	|| ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" �����ھ��������̵�����.\n");
    return 1;	
   }
   else 
   {
   message_vision(HIC "½������$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("literate",1) < 40 ) {
        command("say ���ѧ��̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query("shen") > -0  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
