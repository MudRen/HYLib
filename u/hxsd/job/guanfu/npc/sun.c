// sun ������  
 
inherit NPC;
 
void create()
{
	set_name("������", ({ "sun sanhui", "sun" }));
	set("nickname", "�������");
	set("long", 
        "ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
	set("gender", "����");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen", -8000);
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
	 set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "strike.sanhua" :),
         }));
         set_skill("force", 140);
         set_skill("hunyuan-yiqi", 140);
         set_skill("dodge", 140);
  

        set_skill("kunlun-shenfa", 140);
        set_skill("strike", 140);
        set_skill("sanhua-zhang", 140);
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "sanhua-zhang");
  	map_skill("parry", "sanhua-zhang");
  	prepare_skill("strike", "sanhua-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
