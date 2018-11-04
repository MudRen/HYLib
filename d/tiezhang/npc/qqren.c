// qqren.c ��ǧ��

inherit NPC;
int ask_qiubai();
inherit F_MASTER;
#include "tz_job1.c"

void create()
{
    set_name("��ǧ��", ({ "qiu qianren", "qiu", "qianren", "ren"}));
    set("nickname", "����ˮ��Ư");
	set("long", 
        "����������������ư�İ���-����ˮ��Ư��ǧ��\n"
        "����һ��������ͷ�����Ƹ���������ֻ���һ�Ѵ����ȡ�\n");
	set("gender", "����");
	set("age", 60);
    set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 55);
	set("int", 50);
	set("con", 58);
        set("dex", 55);
	
	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

    create_family("���ư�", 14, "����");

    set("inquiry", ([
"name" : "�Ϸ���ǡ�����ˮ��Ư����ǧ�������Ϸ�������ʲô��ô��\n",
"here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
"�Ϲٽ���" : (: ask_qiubai :),
                       "����" : (: ask_job1 :),
                       "����" : "��ȥ���߷���Ҫ�ɣ�", 
                       "work" : (: ask_job1 :),
                       "tools" : "��ȥ���߷���Ҫ�ɣ�", 

    ]));

	setup();
//	carry_object(__DIR__"obj/black-cloth")->wear();
carry_object(__DIR__"obj/hammer");
	carry_object(__DIR__"obj/black-cloth")->wear();
}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
 
       add_action("do_task","task"); 
     
}
void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -10000) {
                command("hehe");
                command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
                return;
        }
                command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
                command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
int ask_qiubai()
{
say("������ʦ��������ʮ�����������ȹ�����֮�����ж�ͼ������ȫ\n"
    "���书�������ܡ���ϧʮ��ǰ�����ں�������Χ������������\n");
return 1;
}
