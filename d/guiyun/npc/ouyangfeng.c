// /d/guiyun/ouyangfeng.c
// Last Modified by Sir 03/05/2003

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		+"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		+"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIY "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");
	set("no_get",1);

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 12500);
	set("max_qi", 12500);
	set("jing", 11900);
	set("max_jing", 11900);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 50);

	set("combat_exp", 13000000);
	set("score", 200000);

	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);

	set("qi", 19500);
	set("max_qi", 19500);
	set("jing", 16900);
	set("max_jing", 16900);
	set("neili", 28000);
	set("max_neili", 28000);
	set("jiali", 150);

	set("combat_exp", 6500000);
	set("score", 200000);
set_skill("qixian-wuxingjian", 300);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 300);
set_skill("zhaosheshu", 300);
set_skill("yangsheshu", 300);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike",170);
	set_skill("hand",170);
	set_skill("training",300);
	set_skill("staff", 250);
	set_skill("hamagong", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	set_skill("hamashengong", 300);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );

	create_family("����ɽ��",1, "��ɽ��ʦ");
	set("chat_chance",2);
	set("chat_msg",({
		"ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
		"ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
		"ŷ������������ն����������ģ�\n",
	}));
	
	set("inquiry", ([
		"name":   "���֣���...��û�����֣���...����˭?",
		"����":   "���֣���...��û�����֣���...����˭?",
	]));
	setup();
//	carry_object(WEAPON_DIR"treasure/lingshezhang")->wield();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object(__DIR__"obj/baipao")->wear();
	add_money("silver",50);
}


