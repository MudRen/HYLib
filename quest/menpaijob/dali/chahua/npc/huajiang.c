//Cracked by Kafei
// dali ����
// by acep

inherit NPC;

int do_work();
string ask_me();

void create()
{
        set_name("����", ({ "hua jiang","huajiang" }) );
        set("gender", "����");
        set("age", 50);
        set("long",
                "����һλ�ϻ�����������������������ݵĹ��������ڴ�����ҿᰮ�軨�����Ĺ����������ӡ�\n");
        set("combat_exp", 3000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("apply/attack", 10);
        set("apply/defense", 10);

        set_skill("blade", 35);
        set_skill("unarmed", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
        
        set("inquiry", ([
                "�軨" : "�Ҿ�������ר�Ÿ����ֲ軨�ģ�����󲿷ֵ�����Ʒ�ֶ������ֵġ�",
                "����" : "���������Ӧ��Ϊ�����������µģ����ٵ��Ӿ������⻨԰��ɵ���",
                "�ɻ�" : (: ask_me :),
                "job" : (: ask_me :),
                ]));

        setup();

        carry_object(__DIR__"huachu")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

void init()
{
        add_action("do_work", "work");
}

string ask_me()
{
        object me;
        me=this_player();

        if (strsrch(file_name(environment(me)), "/quest/menpaijob/dali/chahua/garden3") == -1)
                return "Ҫ�ɻ��԰ȥ���Ұɡ�";
        if (me->query("family/family_name")!="����μ�")
                return "�Բ������ʵ�������һ�������������";
        if (me->query_temp("garden_working"))
                return "���Ȱ���ͷ�Ļ������˵�ɡ�";
        if (this_object()->is_busy())
                return "��һ�£�����ͷæ���ء�";

//        if (me->query_temp("worktimes",1) > 50)
//                {
//                me->apply_condition("work", 5);
//                me->set_temp("worktimes", 0);
//                return "�����˲��ٻ��ˣ���ȥ��Ϣһ��ɡ�";
//                }
//        if (me->query_condition("work",1) >0)
//                return "�����˲��ٻ��ˣ���ȥ��Ϣһ��ɡ�";
this_object()->start_busy(2);
        me->set_temp("garden_working",random(20)+8);
        me->set_temp("working_times",0);
        return "�ü��ˡ�����������Ҫ��������԰�ӣ�����ҳ��������ɡ�";
}

int do_work()
{
        object me, ob, weapon;
        me=this_player();

        if( strsrch(file_name(environment(me)), "/quest/menpaijob/dali/chahua/garden3") == -1 )
                return notify_fail("�����ڴ���Ժ����ܸɻ");
        if (me->query("family/family_name")!="����μ�")
                return notify_fail("���Ǵ���μҵģ����ܸɻ");
if (me->query("qi") <30)
                return notify_fail("����������ˡ�");
if (me->query("jing") <30)
                return notify_fail("��ľ������ˡ�");

        if (me->query_temp("garden_working")) {
                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");

                tell_object(me, "��������ȥ�������ࡣ\n");

                if (!objectp(weapon=me->query_temp("weapon"))
                        || weapon->query("id")!="huachu")
                {
                        message_vision("$N����ȥ�β����࣬��������Ǵ̣���Ѫ���ܡ�\n", me);
                        me->add("jing",-20);
                        me->add("qi", -10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }
                else {
                        message_vision("$N�û������ɵضԸ����Ӳݺ�������\n", me);
                        me->add("jing",-10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }

                if ( random(me->query("dali/jobdone")) > 650
                && (!present("dang gui", me)) && (!present("da xueteng", me))
                && (me->query("dali/jobdone")) >= 200
                && me->query("combat_exp",1) > 305000 && random(7) == 1 ) {
                        switch (random(5)) {
                        case 0:
                                ob=new(__DIR__"yao/danggui");
                                break;
                        case 1:
                                ob=new(__DIR__"yao/xueteng");
                                break;
                        case 2:
                                ob=new(__DIR__"yao/swjing");
                                break;
                        case 3:
                                ob=new(__DIR__"yao/swjing");
                                break;
                        case 4:
                                ob=new(__DIR__"yao/danggui");
                                break;
                        }
                        message_vision("$N���ĵظ��ŻͻȻ�䷢���Ӳ���������ƺ���ʲô�ر�Ķ�����\n", me);
                        message_vision("$N�������ڳ�һ��"+ob->name()+"��\n", me);
                        ob->move(me);
                }

                if (me->query_temp("working_times")>=me->query_temp("garden_working"))
                {
                        message_vision("������$N���ͷ�������˵�������ˣ����ˣ�����Ļ�͸ɵ�����ɡ�\n", me);
                        message_vision("������$N�����Ĵָ������������㣬�г�һ�ձس�һ���󻨽���\n", me);
                        me->delete_temp("working_times");
                        me->delete_temp("garden_working");
                        me->add("dali/jobdone", 1);
                        me->add("combat_exp", random(22)+10);
                        me->add("potential", random(12)+5);
                        me->add_temp("worktimes", 1);
this_object()->start_busy(2);
                }
                return 1;
        }
        return 0;
}

int accept_object(object who, object ob)
{
        if (who->query("family/family_name")!="����μ�")
                        return notify_fail("�Բ����㲻����������ˡ�\n");
        if (who->query_temp("garden_working"))
                        return notify_fail("���Ȱ���ͷ�Ļ������˵�ɡ�\n");
        if (who->query_condition("dlwork",1))
                        return notify_fail("��ո��ҹ��軨,�����Ҳ����ˡ�\n");


        if (ob->query("id")=="cha hua"
                && ob->query("material")=="wood")
        {
                message_vision("�����˸߲��ҵش�$N����ӹ��軨�����ü��ˣ�����������Ҫ��Ʒ�֣���\n",who);
                command("thank "+getuid(who));
                who->apply_condition("dlwork", 2);
                who->set("dali/jobdone", who->query("dali/jobdone")+1);
                who->add("combat_exp", random(40)+30);
                who->add("potential", random(20)+15);
//        destruct(ob);
                call_out("destroying", 0, ob);
                return 1;
        }
}

void destroying(object ob)
{
        destruct(ob);
        return;
}
