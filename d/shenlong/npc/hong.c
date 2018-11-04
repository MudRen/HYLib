// hong.c �鰲ͨ

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
// int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("�鰲ͨ", ({ "hong antong", "hong" }));
	set("title",  "�����̽���" );
        set("nickname", HIR "�����ɸ�" NOR);
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲ͨ��\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("shenlong-xinfa", 200);
        set_skill("dodge", 180);
	set_skill("yixingbu", 160);
        set_skill("unarmed", 200);
	set_skill("shenlong-quanfa", 200);
        set_skill("parry", 150);
        set_skill("staff", 200);
	set_skill("shedao-qigong", 180);
	set_skill("literate", 100);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong-quanfa");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
        set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "\n�㲻������ǲ���?\n",
		"����" :  "\n�Ҿ��������̽���.\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ƾ����" + RANK_D->query_rude(this_player())+",Ҳ����̫��үͷ�϶���?\n") :),
		(: command("say ���ò��ͷ�����������\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}



int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say ��Խ����Խ��׵������Ե׵ġ�");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say �Һ鰲ͨ�������������ʥ����ô������");
                message_vision("�鰲ͨ΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵��ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "���겻��") >=0 && (strsrch(arg, "�����ɸ�") >=0
         || strsrch(arg, "��������") >=0 || strsrch(arg, "������ʥ") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
	        this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// ���겻��,�����ɸ�,��������,������ʥ

/* int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="hong" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("learnhong"))
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   write("�鰲ͨЦ��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 200/   \n"+
"  �����ڹ� (force)                         - ��ɲ� 200/    \n"+
"����Ԫһ���� (hunyuan-yiqi)                - ��ɲ� 150/    \n"+
"  ����д�� (literate)                      - ��ɲ� 200/    \n"+
"  �����м� (parry)                         - ��ɲ� 150/    \n"+
"���ߵ��湦 (shedao-qigong)                 - ��ɲ� 200/    \n"+
"��������ʽ (shenlong-bashi)                - ��ɲ� 200/    \n"+
"  �����ȷ� (staff)                         - ��ɲ� 200/    \n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 200/    \n"+
"  �����ķ� (shenlong-xinfa)                - ��ɲ� 200/    \n"+
"�����β� (yixingbu)                        - ��ɲ� 200/    \n");
return 1;
}
*/

void die()
{
message_vision("\n$N���������,��Ȼ������ɱ����,....��˵���������۵������ˡ�\n", this_object());
::die();
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "�鰲ͨ˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "�鰲ͨ��$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "�鰲ͨ��$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
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
   message_vision(HIC "�鰲ͨ��$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void init()
{
	object ob;

	::init();
// add_action("do_skills","skills");
// add_action("do_skills","cha");
add_action("do_flatter", "flatter");
add_action("do_join","join");

	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("shenlong-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 80 ) {
        command("say ��ı����ȷ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
