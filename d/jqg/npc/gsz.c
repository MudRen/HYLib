// gsz.c ����ֹ
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void create()
{
	set_name("����ֹ", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","��ĿӢ����͸�������߾�֮�ţ�ֻ����ɫ���ƣ����տ��¡�\n");
        set("title",HIW"����ȹ���"NOR);
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
set("pubmaster",1);
	set("str", 55);
	set("int", 54);
	set("con", 58);
	set("dex", 56);
        set("per", 50);
        set("unique", 1);

	set("max_qi", 18500);
	set("max_jing", 18000);
	set("neili", 28000);
	set("max_neili", 28000);
        set("jing", 22000);
        set("max_jing", 22000);
        set("eff_jing", 22000);
	set("jiali", 80);
	set("combat_exp", 5500000);
 
        set_skill("sword", 200);      
        set_skill("blade", 200);
        set_skill("force", 200);      
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("guiyuan-tunafa", 200);
        set_skill("literate", 200); 
        set_skill("shuishangpiao", 200);
        set_skill("tiezhang-zhangfa", 200);
        set_skill("strike",200);
        set_skill("sword", 200);
	set_skill("heijian-jindao", 300);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "heijian-jindao");
	map_skill("sword", "heijian-jindao");
	map_skill("blade", "heijian-jindao");
        prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.daojian" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.nizhuan" :),
                (: perform_action, "sword.yinyang" :),
                (: perform_action, "strike.tianlei" :),
                (: perform_action, "strike.tiezhangxianglong" :),
                (: perform_action, "strike.zhangdao" :),
        }) );
     set ("chat_chance",50);
     set ("chat_msg", ({
                      (: random_move :)
                      }) );
        set("inquiry", ([
            "���鵤": "��ҩ�޶࣬����Ҳ�������ƣ����򲻵��ѡ�����",
            "�����": (: ask_gu :),
        ]) );
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/misc/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"����̫�������������ΪΣ�գ����ǲ�Ҫ�ڴ˾����ˡ�";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"��Ȼ�Ծ����������Ȥ��������㿴���ɡ�";
}


int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeh"))      
		who->set_temp("learn_timeh", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("heijian-jindao",1)<30)
		i=ob->value() / 150;
	else
	{
		if(who->query_skill("heijian-jindao",1)<60)
			i=ob->value() / 200;
		else
		{
			if(who->query_skill("heijian-jindao",1)<100)
				i=ob->value() / 300;
			else
				i=ob->value() / 500;
		}
	}
if (random(3)==0)
{
if (i < 1) i=0;
	who->add_temp("learn_timeh",i);

      message_vision("����ֹ��$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
}
      message_vision("����ֹ��$N˵����лл�ˣ����ñ���ȱǮ�á�\n",who);
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeh") <= 0) return 0;
else         
ob->add_temp("learn_timeh",-1);
return 1;
}
