#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("Слѷ", ({"xie xun", "xie", "xun", }));
	set("long",
        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"
        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"
	);

	set("title",HIG "����" HIY "��ëʨ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 8500);
	set("max_jing", 8500);
	set("neili", 8000);
	set("max_neili", 33000);
	set("jiali", 250);

	set("combat_exp", 1900000);
	set("score", 800000);

    	set_skill("force", 260);
	set_skill("dodge", 240);
	set_skill("sword", 240);
	set_skill("blade", 240);
	set_skill("parry", 240);
	set_skill("cuff", 300);
	set_skill("blade", 220);
	set_skill("jinwu-daofa", 240);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 240);
    	set_skill("damo-jian", 240);
    	set_skill("qishang-quan", 300);
    	set_skill("hunyuan-zhang", 250);
    	set_skill("literate", 200);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
	}) );
	create_family("����",34, "����");
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");

}



