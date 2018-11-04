// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();

void create()
{
    set_name("������", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "��������" NOR );
    set("gender", "����");
    set("title", "������̹�����ʹ");
    set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
    set("age", 45);
    set("shen_type", -1);

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "����ͤ"     : "�����ˣ���ɱ��\n",
      "��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
      "ɱ��������" : (: ask_kill() :),
      "������"     : "��������������ʮ��......\n",
    ]));
    set("qi", 14000);
    set("max_qi", 14000);
    set("jing", 21000);
    set("max_jing", 21000);
    set("neili", 23500);
    set("max_neili", 23500);
    set("jiali", 350);

    set("combat_exp", 6500000);
    set("score", 0);

    set_skill("force", 310);
    set_skill("hunyuan-yiqi", 310);
    set_skill("dodge", 110);
    set_skill("shaolin-shenfa", 310);
    set_skill("finger", 310);
    set_skill("strike", 310);
    set_skill("hand", 310);
    set_skill("claw", 310);
    set_skill("parry", 310);
    set_skill("nianhua-zhi", 310);
    set_skill("sanhua-zhang", 310);
    set_skill("fengyun-shou", 310);
    set_skill("longzhua-gong", 310);
    set_skill("buddhism", 110);
    set_skill("literate", 110);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("finger", "nianhua-zhi");
    map_skill("strike", "sanhua-zhang");
    map_skill("hand", "fengyun-shou");
    map_skill("claw", "longzhua-gong");
    map_skill("parry", "nianhua-zhi");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
    prepare_skill("finger", "nianhua-zhi");
    prepare_skill("strike", "sanhua-zhang");
    create_family("�������", 2, "������ʹ");

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
    command("say �Ҳ��յ��ӡ�\n");
    return;
}

int ask_kill()
{
   object ob,me = this_player();

   command("tell "+this_player()->query("id")+" ��Ҫȥɱ�������ܣ�\n");
   message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����\n" NOR,this_player());
   ob=new("/d/heimuya/npc/obj/card4");
   ob->move(me);
   tell_object(me,"������ӻ�������һ����������������ϡ�\n");
   return 1;
}
