#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����˼", ({ "ling tuisi", "ling" }));
        set("title","����");
        set("long","����˼��ò���㣬���ݺ��Ǵ��顣����Ȼ���н�ʿ���������֣�\n"
        "��ʵ����ɳ��Ĵ���ͷ�������Ĳų��ڣ��书Ҳʮ���˵á�\n");
        set("gender", "����");
        set("age", 45);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);

        set("combat_exp", 25000);
        set("shen_type", -1);
        setup();
        add_money("silver", 50);
        carry_object("/clone/armor/cloth")->wear();
}
        
int accept_kill(object me)
{
        command("say ���컯��֮�¾����ں��ָ������ף�û��������\n");
            me->apply_condition("killer", 20);
        kill_ob(me);
        return 1;
}
