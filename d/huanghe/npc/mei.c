// mei.c
inherit NPC;
#include <ansi.h>;
void create()
{
        set_name( "÷����" ,({ "mei chaofeng", "mei" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIB"��ʬ"NOR);
        set("gender", "Ů��");
        set("age", 32);
        set("long",
            "÷�����ǻ�ҩʦΨһ��Ů���ӣ��������ܻ�ҩʦ�۰�����ϧ����ʦ�ֳ�����\n"
            "������㺣�����͵�ˡ������澭�¾�˽����\n"
            "����ɫ�����Ϊ�þӺ����Ե���ڣ�ģ��ȴ��Ϊ�����������һ��������Ⱦ�\n"
            "ͨ�޷���\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",6500);
        set("max_jing",6000);
        set("neili", 22500);
        set("max_neili", 22500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1200000);

        set_skill("claw", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 120);
        set_skill("jiuyin-baiguzhao", 290);
        set_skill("bibo-shengong", 290);
        set_skill("anying-fuxiang", 290);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
           "��ʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "����":     "�ߣ��������С�Ӱ�������ʦ�磬�Ҿ�����Ź�����",
           "�":     "�������ҵ�ͽ�ܣ��������ô��",
           "÷����":   "��������ô�����ǰ׳հ���",
           "������":   "�����ҵ�ʦ�磬Ҳ���ҵķ������ϧ��������С�������ˡ�",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

