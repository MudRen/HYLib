//  zheng  ֣����
 
inherit NPC;
 
void create()
{
	set_name("֣����", ({ "zheng qimie", "zheng" }));
	set("nickname", "�������");
	set("long", 
        "ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -6000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 600000); 
	  
         set_skill("force", 150);
         set_skill("xuantian-wuji", 150);
         set_skill("dodge", 150);
  

        set_skill("kunlun-shenfa", 150);
        set_skill("cuff", 150);
        set_skill("wenjia-quan", 150);
        set_skill("parry", 150);
        set_skill("murong-daofa", 150);
        set_skill("blade", 150);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("blade", "murong-daofa");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "murong-daofa");
  	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield(); 
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
