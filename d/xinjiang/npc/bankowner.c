#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "man in white" }) );
        set("gender", "����");
        set("combat_exp", 3500000);
        set("title", HIW "һ������"NOR);
        set("long",
                "�������������Ƕ�ʮ��ǰ���Ѿ����������ģ�һ���ɻ��������죬��
����ȴվ������һ��������\n"
        );
        set("reward_npc", 1);
        set("difficulty", 5);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",30);
        
        set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("sword",180);
        set_skill("feixian-sword",150);
        set_skill("feixian-steps",150);
        set_skill("unarmed",200);

        set_skill("parry",150);
        
        map_skill("parry","feixian-sword");

        map_skill("dodge","feixian-steps");
        map_skill("sword","feixian-sword");
        map_skill("move","feixian-sword");
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
   carry_object(__DIR__"obj/hua_sword")->wield();
}      
