// huangxu daoren �������
inherit NPC;
 
void create()
{
	set_name("�������", ({ "huangxu daoren", "daoren" }));
//	set("nickname", "");
	set("long", 
        "�䵱����ͽ��Ϊ�˼�թ��������Щ���¡�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5500);
	set("max_jing", 5400);
	set("neili", 5700);
	set("max_neili", 5700);
	set("jiali", 10);
	set("combat_exp", 75000 + random(40000)); 
	 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 50);
        set_skill("taiji-shengong", 320);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 50);
        set_skill("unarmed", 50);
        set_skill("taiji-quan", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("liangyi-jian", 50);
        set_skill("taiji-jian", 50);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
