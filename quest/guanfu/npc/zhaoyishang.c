//  zhaoyishang ��һ��
 
inherit NPC;
 
void create()
{
	set_name("�����һ��", ({ "zhao yishang", "zhao" }));
	set("nickname", "�������");
	set("long", 
        "ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -8000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 800000); 
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         })); 
         set_skill("force", 100);
         set_skill("xuantian-wuji", 320);
         set_skill("dodge", 120 + random(30));
  

        set_skill("kunlun-shenfa", 140);
        set_skill("strike", 120 + random(30));
        set_skill("kunlun-zhang", 120 + random(30));
        set_skill("parry", 140);
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
