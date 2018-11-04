// duanzc.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "duan zhengchun", "duan" }));
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 12500);
	set("max_jing", 11220);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 300000);

        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
        set_skill("finger", 150);
	set_skill("kurong-changong", 380);
        set_skill("tiannan-step", 350);
        set_skill("jinyu-quan", 330);
        set_skill("wuluo-zhang", 350);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 380);
//        set_skill("sun-finger", 100);
	set_skill("literate", 100);

	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

	setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);

	create_family("����μ�",18,"������");
}

void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("title");
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	oldtitle = ob->query("title");
	if (strsrch(oldtitle, "������������") >= 0) 
	{
		command("say �ܺã���Ȼ���������͵�����Ϊ����");
		command("recruit " + ob->query("id"));
		ob ->set("title", oldtitle);
	}
	else
	{
		command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
		return;
	}
}
