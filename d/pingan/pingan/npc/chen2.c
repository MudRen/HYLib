// chen.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��С��", ({ "chen xiaode", "chen" }));
        set("long", "��С����ƽ����ݹݳ�����������ݳ��е½�ͷ���׵ܵܡ�\n");
        set("gender", "����");
        set("age", 45);
        set_skill("dodge", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("claw", 40);
        set_skill("hand", 40);
        set_skill("strike", 40);
        set_skill("finger", 40);
        set_skill("cuff", 40);
        set_skill("blade", 40);
        set_skill("stick", 40);
        set_skill("club", 40);
        set_skill("staff", 40);
        set_skill("sword", 40);
        set_skill("throwing", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 5000)
    {
        message_vision("��С������$N˵������书Ӧ���������������ٳ�����������û
�������ˡ�����������ѧϰ��ȥ������ȥ���ݳ����Ҹ���е¡�\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/pingan_paied",1);
        message_vision("��С�¶�$N˵���ã���λ" + RANK_D->query_respect(who) 
+ "��ѧʲô�أ�\n" , who);
        return 1;
    }
    else
        message_vision("��С����ü��$N˵��Ǯ�Ҳ��ں�������Ҳ����Ҳ̫���˵���ɣ�\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/pingan_paied")==1) return 0;
        return 1;
}


