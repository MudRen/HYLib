// guo ����ȭ
 
inherit NPC;
 
void create()
{
        set_name("����ȭ", ({ "guo sanquan", "guo" }));
        set("nickname", "��ȭ����");
        set("long", 
        "��ȭ�ŵ�������һ��ȭ��С��������\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen", -2000);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        set("combat_exp", 280000); 
         
         set_skill("force", 100);
         set_skill("hunyuan-yiqi", 100);
         set_skill("dodge", 100);
  

        set_skill("shaolin-shenfa", 100);
        set_skill("cuff", 140);
        set_skill("parry", 100);
        set_skill("wenjia-quan", 120);
        set_skill("literate", 60);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "wenjia-quan");
        map_skill("parry", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}

#include "/quest/guanfu/npc/npc.h"
