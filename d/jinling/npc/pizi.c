
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("СƦ��", ({ "pizi" }) );
        set("title", "Ʀ�Ӱ�");
        set("gender", "����" );
        set("age", 23);
        set("cor", 30);
        set("long",
                
"���Ǹ��ں�ͬ����ŵ�Ʀ�ӣ����ǲ����ǹٱ��������е��ˡ�\n"                              
                "�������Ǿ����۸��ϰ��ա�\n");

        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("max_force", 2000);   
        set("force", 2000);             
        set_skill("unarmed", 10);
        set_skill("parry", 30);
        set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/linen")->wear();
        add_money("gold", 1);
}

int accept_fight(object me)
{
        command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
        command("grin");
        kill_ob(me);
        return 1;
}

