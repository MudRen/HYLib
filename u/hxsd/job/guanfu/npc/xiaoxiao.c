// jianghu xiaoxiao ������С
inherit NPC;
 
void create()
{
	set_name("������С", ({ "jianghu xiaoxiao", "xiaoxiao" }));
//	set("nickname", "");
	set("long", 
        "һ�������Ǻܺã������Ѿ���ʼ���񽭺���С����\n"
        " ��̬�������������ᡣ\n");
	set("gender", "����");
	set("age", random(10) + 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 10);
	set("combat_exp", 75000 + random(40000)); 
	 
         set_skill("force", 60);
         set_skill("xuantian-wuji", 70);
         set_skill("dodge", 60);
  

        set_skill("kunlun-shenfa", 30 + random(50));
        set_skill("strike", 30 + random(50));
        set_skill("parry", 30 + random(50));
        set_skill("kunlun-zhang", 30 + random(50));
        set_skill("literate", 20);
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
