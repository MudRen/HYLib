// /kungfu/class/xueshan/jiumozhi.c �Ħ��
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ħ��", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "��������" NOR);
        set("long",@LONG
������ѩɽ�µ����ţ��˳ƴ����������Ħ�ǡ����Է��о�����о���
��һ��������ģ�ͷ��ɮñ��
LONG
        );
        set("title","ѩɽ������");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("score", 500000);

        set_skill("necromancy", 350);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 350);
        set_skill("lamaism", 250);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 380 );
        set_skill("strike", 200 );
        set_skill("huoyan-dao", 380);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("ѩɽ��", 1, "����");
        set("class", "bonze");

        setup();

//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);
}

void attempt_apprentice(object ob)
{

 		  if ((string)ob->query("gender") != "����") {
        			 command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
		  }

		  if ((string)ob->query("class") != "bonze") {
        			 command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
		  }

        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
		  }

        if ((int)ob->query_skill("lamaism", 1) < 100) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

//        command("chat ������������������");
//        command("chat ��ѩɽ�����Ǻ�����ˣ����ǿ�ϲ�ɺء�");
//        command("chat ������������������");
        command("recruit " + ob->query("id"));

	ob->set("title",HIY"����"NOR);
}
