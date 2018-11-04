// Npc: /kungfu/class/shaolin/da-mo.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("��Ħ����", ({
		"da mo",
		"da",
		"mo",
	}));
	set("long",
		"����һλ���������������ɮ����һϮ���ݽ�˿������ġ�\n"
		"��ȴ�����⣬Ŀ�̴�Ц���������飬һ�ɵõ���ɮ���ơ�\n"
                "�����������ɿ�ɽ���桢�������ֵ�������ɮ��Ħ��ʦ��\n"
	);

	set("title", HIR"���ֿ�ɽ��ʦ"NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("jing", 38000);
	set("max_jing", 38000);
	set("qi", 38000);
	set("max_qi", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 90);
	set("age", 80);
	set("shen_type", 1);
	set("shen", 100000);
	set("str", 150);
	set("int", 50);
	set("con", 50);
	set("dex", 150);
	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 150);
	set("combat_exp", 9800000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 300);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

set_skill("weituo-zhang", 380);
set_skill("shaolin-tantui", 380);
set_skill("jingang-zhang", 380);
set_skill("jimie-zhua", 380);
set_skill("duoluoye-zhi", 380);
set_skill("mohe-zhi", 380);
set_skill("boluomi-shou", 380);
	set_skill("banruo-zhang", 380);
	set_skill("cibei-dao", 380);
	set_skill("damo-jian", 380);
	set_skill("fengyun-shou", 380);
	set_skill("fumo-jian", 380);
	set_skill("hunyuan-yiqi", 380);
	set_skill("jingang-quan", 380);
	set_skill("longzhua-gong", 380);
	set_skill("luohan-quan", 380);
	set_skill("nianhua-zhi", 380);
	set_skill("pudu-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 380);
	set_skill("weituo-gun", 380);
	set_skill("wuchang-zhang", 380);
	set_skill("xiuluo-dao", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yijinjing", 380);
	set_skill("yizhi-chan", 380);
	set_skill("zui-gun", 380);
	set_skill("weituo-chu", 380);
	set_skill("ranmu-daofa", 380);
	set_skill("wuying-jian", 380);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );
	create_family("������", 34, "����");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	setup();
        carry_object("clone/weapon/gangjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] != 36 )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

        if ((ob->query_int() < 40) || (ob->query("PKS") > 3 )) 
        {
                command("say ���¶���һ��Ե�֡�");
                command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
		return;
	}

	if (ob->query_skill("dodge",1)>=150 &&
		ob->query_skill("force",1)>=150 &&
		ob->query_skill("parry",1)>=150 &&
		ob->query_skill("buddhism",1)>=150)
	{
		command("say �����ֵ�һ����֮�ţ����Ǵ��ϻ� !");
		name = ob->query("name");
		new_name = "��" + name[2..3];
		ob->set("name", new_name);
	
		command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɶ��ֱ����� !");
		command("recruit " + ob->query("id"));
	}
	else
		command("say �����ھ�������Ҳ̫���˵�� !");
	return;
}

