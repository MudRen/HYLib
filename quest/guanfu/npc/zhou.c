//   zhou ������
 
inherit NPC;
 
void create()
{
	set_name("���������", ({ "zhou wushu", "zhou" }));
	set("nickname", "�������");
	set("long", 
        "ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -5000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 5800);
	set("max_neili", 5800);
	set("jiali", 100);
	set("combat_exp", 500000); 
	  
         set_skill("force", 130);
         set_skill("xuantian-wuji", 330);
         set_skill("dodge", 130);
  

        set_skill("kunlun-shenfa", 140);
        set_skill("cuff", 130);
        set_skill("wenjia-quan", 150);
        set_skill("parry", 150);
        set_skill("xiaoyao-dao", 150);
        set_skill("blade", 150);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("blade", "xiaoyao-dao");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "xiaoyao-dao");
  	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield(); 
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
