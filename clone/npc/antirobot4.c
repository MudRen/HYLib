// designed by Yu Jue

#include <ansi.h>

inherit NPC;

string *key=({
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������"
});
string ans="";
object ob;
int timer = 0;
string str = "����ɱ��˵�������� answer �ش��������������ǣ�\n";

void create()
{
    set_name("����ɱ��", ({ "yinyi shashou", "yinyi", "shashou", "runner" }));

    set("gender", "����");
    set("age", 20);
    set_temp("apply/long", 
        ({ "����һ��ר��׷�������˵Ļ���̽Ա��\n"
           "������û����Զ��ش����⣬��������������ɾ����\n"})
    );
    set_skill("dodge", 1000);
    set("max_qi", 10000);
    set("qi", 10000);
    set("max_jing", 10000);
    set("jing", 10000);
set("attitude", "aggressive");
    set("combat_exp", 5000000);
        
    set("inquiry", ([
        "name": "�㻹�����й��򰡣�ר�Ļش�����ɣ�",
        "rumors": "��˵�л����˻��뱾MUD���ٺ٣��ҿ��ǻ��۽�ѽ��",
    ]) );
        set("attitude", "friendly");

    setup();
}

void question()
{
    if (!ob) return;
    tell_object(ob, HIW+str+NOR);
}

void init()
{
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
        this_object()->test_player(ob);
        }
    if (this_player() == ob) {
        remove_call_out("question",);
        ob->start_busy(3);
        this_object()->test_player(ob);
        call_out("question", 0);
        add_action("do_answer", ({ "answer", "da", "huida" }));
        add_action("wait", ({ "use","gohome","exert","perform","yong","fastmove","zhaohuan","quit","home","whistle","chen","mache","use","quit", "learn", "xue", "study", "du", "sleep", "practice", "lian" }));
    }
}

int wait()
{
        write("�Բ������Ȼش����⡣\n");
        return 1;
}

void kill_ob(object ob)
{
    ob->remove_killer(this_object());
    remove_killer(ob);
    message_vision("$N��ɥ�ط�������ɱ�ָ����������ս����\n", ob);
}

void unconcious()
{
    reincarnate();
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("eff_jing", query("max_jing"));
    set("jing", query("max_jing"));
    set("jingli", query("eff_jingli"));
    say("����ɱ����Ц��˵�������޵в����棡\n");
    command("hehe");
}

void die()
{
    unconcious();
}

int do_answer(string arg)
{
    object me = this_object();
    int len = strlen(ans);

    if (!arg || strlen(arg) != len)
        return notify_fail("�𰸵ĳ��Ȳ��ԣ�����ϸ������\n");
    if (arg==ans) {
                ob->set("startroom", "/d/city/wumiao");
        message_vision("$N���˵�ͷ��˵����OK��$n����æ�ɡ�\n", me, ob);
        message_vision("$NͻȻ��ʧ�����ˡ�\n", me); 
    } else {
        message_vision("$N̾�˿�������"+arg+"��"+ans+"�Ŷԣ���ô�򵥶��𲻳���ȥ��ͥ������Ѷ�ɣ�\n", me);
        message_vision("$N��$n��ȥ�˷�ͥ��\n", me, ob);
        ob->move("/d/wizard/robot_court");
     ob->apply_condition("jyrobot",30+random(30));
ob->set("startroom", "/d/wizard/robot_court");
    }
    destruct(this_object());
    return 1;
}

void test4()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer--;
        if (timer > 0) {
            tell_object(ob, "����ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
            call_out("test4", 1);
        } else {
            tell_object(ob, "����ɱ��̾�˿�������һ�㷴Ӧ��û�У�����һ���������ӷ���ȥ��ͥ������Ѷ�ɣ�\n");
            me->start_busy(10);
            message_vision("$N��$n��ȥ�˷�ͥ��\n", me, ob);
            ob->move("/d/wizard/robot_court");
            destruct(me);
        }
    } else destruct(me);
}

void test3()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 10;
        tell_object(ob, "����ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
        me->start_busy(10);
        call_out("question", 1);
        if (timer > 10) call_out("test3", 10);
        else call_out("test4", 1);
    } else destruct(me);
}

void test2()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 30;
        tell_object(ob, "����ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n");
        me->start_busy(10);
        call_out("question", 1);
        if (timer > 60) call_out("test2", 30);
        else call_out("test3", 10);
    } else destruct(me);
}

void test1()
{
    object me = this_object();

    if (ob && interactive(ob)) {
        if (environment() != environment(ob))
            me->move(environment(ob), 1);
        timer -= 60;
        tell_object(ob, "����ɱ�־����㣺�㻹��" + chinese_number(timer / 60) + "���ӵĿ���ʱ�䡣\n");
        call_out("question", 1);
        if (timer > 120) call_out("test1", 60);
        else call_out("test2", 30);
    } else destruct(me);
}

void test_robot(object obj)
{
    int len, temp, line, ltemp, c, cl;
    object me = this_object();

    ob = obj;
    if (environment(ob)) {
        me->move(environment(ob), 1);
        message_vision("$N��Ȼ������$n��ǰ��\n", me, ob);
        set_leader(ob);
        ob->set("startroom", "/d/wizard/robot_court");
        tell_object(ob, "����ɱ���Դ�Ǹ���˵���������˻��飬���й��£���ش�һ��С���⡣��\n");
        temp = len = random(3) + 3;
        while (temp--) {
            ans += "0";
            ans[<1] += random(10);
        }
        line = random(5)*6;
        for (ltemp = line; ltemp < line+6; ltemp++) {
            for (temp = 0; temp < len; temp++) {
                c = ans[temp] - '0';
                if (c != 1) cl = 7;
                else cl = 3;
                if (c > 1) c = c * 8 - 4;
                else c *= 8;
                cl += c;
                str += key[ltemp][c..cl];
            }
            str += "\n";
        }
        timer = 180;
        call_out("test1", 60);
    } else destruct(me);
}

void test_player(string player)
{
//    object ob = find_player(player);

    if (ob && interactive(ob))
        test_robot(ob);
}
