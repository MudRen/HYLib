//  quan ȫ����
 
inherit NPC;
 
void create()
{
	set_name("ȫ����", ({ "quan erfeng", "quan" }));
//	set("nickname", "");
	set("long", 
        "�����ɵ���ͽ����һ��Ͷ����͢������һ�ź������������Ŀ������\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen", -5000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 6200);
	set("max_jing", 6200);
	set("neili", 6200);
	set("max_neili", 6200);
	set("jiali", 100);
	set("combat_exp", 380000 + random(120000)); 
	 
         set_skill("force", 100);
         set_skill("xuantian-wuji", 320);
         set_skill("dodge", 120);
  

        set_skill("kunlun-shenfa", 120);
        set_skill("strike", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("kunlun-zhang", 120);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
