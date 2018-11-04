// /u/poq/sdxl/npc/choudiao.c ���
// by poq@jyqx 97/7
// amend dubei

inherit NPC;

void create()
{
    set_name("���", ({ "chou diao","chou","diao"}) );
    set("long", @LONG
��ǰ��Ȼ��һͷ����ǵ��������ޣ����˻��ߣ���ò��ª֮����ȫ����ë��
�����䣬���Ǳ��˰�ȥ��һ����Ƶģ�ëɫ�ƺڣ��Ե����ǰ��࣬ģ�����һ�����
��˫��Ҳ��������ƣ���ȴ������Զ���������������ͷ��������Ѫ���
����������������ǧ�򣬴�δ������˹�׾��������ݡ����������������ȥ��
˫����֣���ʱ�������ȴ�����̣���֪��η��裬ֻ�Ǹ�������������һ����
�����š�
LONG
    );
    set("gender", "����");
    set("age", 100);
    set("attitude", "peaceful");
    set("shen_type", 0);
    set("str", 44);
    set("int", 38);
    set("con", 42);
    set("dex", 44);

    set("max_qi", 2400);
    set("max_jing", 2400);
    set("neili", 2400);
    set("max_neili", 2400);
    set("combat_exp", 800000);
    set_skill("force", 180);
    set_skill("dodge", 180);
    set_skill("unarmed", 180);
    set_skill("whip", 180);
    set_skill("parry", 180);
//    set("unique", 1);
//    set("startroom","/u/dubei/sdxl/pubu");

    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
    set("dan_count", 2);
    setup();

    set("chat_chance", 15);
    set("chat_msg", ({
        "�������ͷ��������������\n",
        (: random_move :),
    }) );
}
void init()
{
        object me, ob, where, ob0;
        ::init();
        ob = this_player();
        me = this_object();
        where = environment(me);
        if (interactive(ob = this_player()) && !is_fighting()
         && random(ob->query("kar"))+10>27 && query("dan_count") > 0
         && random(20)<5 ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob,me,where,ob0);
        }       
 
}

void greeting(object ob,object me,object where,object ob0)
{
        write("ͻ��һ���ȳ�֮�������д���֮�඾�������ڽ���\n");
        message_vision("�����ͷ�����������������������������ս��\n",me);
        add("dan_count", -1);
        ob0 = new( __DIR__"dumang");
        ob0->move(where);
        message_vision("һ������ͻȻ���˳������������ס�\n",me);
        me->kill_ob(ob0);
        ob0->fight_me(me);
        
}
