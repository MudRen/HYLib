// yamen_police.c
#include <ansi.h>
inherit NPC;

void create()
{
     string *surname=({"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ","����","����",});
     set_name(surname[random(sizeof(surname))]+"Ѳ��", ({ "xun bu","police"}) );
     set("gender", "����" );
     set("no_get",1);
     set("no_put",1);
     set("age", 25);
     set("str", 65);
     set("cor", 60);
     set("dex", 60);
     set("cps", 65);
     set("int", 60);
     set("per", 60);
     set("kar", 65);
     set("long",@LONG
Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����
LONG
);
     set("status","patrol");
     set("CatchWho",0);
      set("combat_exp", 12000000);
     set("attitude", "heroism");
     set ("inquiry",([
                "bribery":
"˵���ﻰ������̫ү��ƶ���������������µ�������û����������\n"+
"�������Ǯ�ɣ�\n",
                "salary":
"������үٺ��΢�������ǵ�������Ȼ������......\n",
                "money":
"˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸(give)��\n����Ҳ�ðǲ�Ƥ\n
",
                        ]));
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
        	(: command("unwield sword") :),
                  (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                (: perform_action, "parry.anran" :),
                (: perform_action, "sword.feihongrudian" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.botao" :),
                (: perform_action, "sword.lei" :),
                (: perform_action, "sword.juan" :),
                (: perform_action, "sword.dong" :),
                (: perform_action, "sword.dang" :),
                (: perform_action, "sword.hai" :),					
                (: perform_action, "sword.qianjun" :),						

        }) );
     set ("chat_chance",50);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );
     set("pursuer",1);
        set("jing",200000);
        set("max_jing",200000);
        set("eff_jing",200000);
        set("qi",200000);
        set("max_qi",200000);
        set("eff_qi",200000);
        set("neili",200000);
        set("max_neili",200000);
	set("jiali",50);
	set_skill("sword", 700);
	set_skill("force", 700);
	set_skill("unarmed", 700);
	set_skill("dodge", 700);
	set_skill("parry", 700);
	set_skill("anranxiaohun-zhang",700);
	set_skill("xuantie-sword", 750);
	set_skill("xiantian-qigong", 700);
	set_skill("yunv-shenfa",700);
	set_skill("yunv-xinfa",700);
	set_skill("yunv-shenfa",700);
        set_skill("yunv-jian", 720);  
        set_skill("tianluo-diwang", 720); 
                set_skill("meinv-quan", 720); 
                        set_skill("wuzhan-mei", 720); 
                                set_skill("yinsuo-jinling", 720);   

	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	map_skill("force", "yunv-xinfa");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);

     setup();
     //carry_object("/quest/shenshu/book1test");
     carry_object("/clone/weapon/changjian")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
	ob->apply_condition("qx_snake_poison",220);
                ob->start_busy(6);
		remove_call_out("kill_ob");
		call_out("follow_ob", 0, ob);
		call_out("kill_ob", 0, ob);
command("kill "+ob->query("id"));
	}
}
void unconcious()
{
    die();
}
int hit_ob(object me, object ob, int damage)
{

if (ob=me)
{
me->add("qi",me->query("max_qi")/20);
me->add("eff_qi",me->query("max_qi")/20);
me->add("jing",me->query("max_jing")/20);
me->add("eff_jing",me->query("max_jing")/20);
me->set("neili",me->query("max_neili"));
}

if (ob!=me)
{
if (me->is_busy())
me->start_busy(1);
ob->start_busy(5);

	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}


int accept_object(object who, object ob)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount,p;
	string wiz_status;
	obj=this_object();
p=0;
        if (! ob->query("money_id"))
        {
               command("say �������ҿ�ûɶ��Ȥ��");
               return 0;
        }

        if (ob->value() < 20000000)
        {
		command("shake " + who->query("id"));
                command("say ˵���ﻰ������̫ү��ƶ���������������µ�������û����������");
                return 0;
        }

        command("say ����������үٺ��΢�������ǵ�������Ȼ������......�Ҿ�ͨһ������ɣ�");
//command("give silver to hxsd");
		inv = all_inventory(obj);
		for(i=0; i<sizeof(inv); i++) {
if(inv[i]->query("dynamic_quest"))
{
message("channel:chat", HIC"��������Ϣ��"GRN + who->query("name")+"�õ�"+HIR"����:" + inv[i]->query("name")+HIG"����\n"NOR,users() );
inv[i]->move(who);
p=1;
}
		}

        if (p ==0 && !ob->query_condition("killer"))
        {
		command("shake " + who->query("id"));
                command("say ��ûʲô���԰����! ");
                return 0;
        }

        if (ob->value() >= 50000000)
{
    command("say �����߰ɣ���Ҫ�����ҿ���......");
        	 who->clear_condition("killer");
}
//      destruct(ob);
        return 1;
}
