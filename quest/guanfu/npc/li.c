//   li ���Ĵ�
 
inherit NPC;
 
void create()
{
        set_name("������Ĵ�", ({ "li sicui", "li" }));
        set("nickname", "�������");
        set("long", 
        "ԭ�������еľ޿ܣ�����Ϊ��ܹٸ��ͳ�ң�������˸������֡�\n");
        set("gender", "����");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -8000);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 6500);
        set("max_jing", 6500);
        set("neili", 6800);
        set("max_neili", 6800);
        set("jiali", 100);
        set("combat_exp", 700000); 
         
         set_skill("force", 140);
         set_skill("xuantian-wuji", 320);
         set_skill("dodge", 120);
  

        set_skill("kunlun-shenfa", 130);
        set_skill("cuff", 160);
        set_skill("sword", 130);
        set_skill("duanjia-jianfa", 140);
        set_skill("wenjia-quan", 160);
        set_skill("parry", 140);
        set_skill("literate", 90);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("sword", "duanjia-jianfa");
        map_skill("parry", "duanjia-jianfa");
        map_skill("cuff", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield(); 
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
