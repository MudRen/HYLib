// shan ����
 
inherit NPC;
 
void create()
{
	set_name("����", ({ "shan zheng", "shan" }));
	set("nickname", "̩ɽ������ͽ");
	set("long", 
        "̩ɽ���ҵ���ͽ�������һ�һ�������е��֡�\n");
	set("gender", "����");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -85000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 850000); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: perform_action, "force.powerup" :),
        }));
        set_skill("force", 160);
        set_skill("huntian-qigong", 150);
        set_skill("dodge", 150);
        set_skill("xiaoyaoyou", 160);
        set_skill("strike", 160);
        set_skill("tiezhang-zhangfa", 160);
        set_skill("parry", 160);
       
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
    
        map_skill("strike", "tiezhang-zhangfa");
  	map_skill("parry", "tiezhang-zhangfa");
  	prepare_skill("strike", "tiezhang-zhangfa");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
      
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
