//  robot-judge.c
//  By Jpei  Aug 1997
//  Add cleaner By Bbb
//  Change question format By Look
inherit NPC;
#include <ansi.h>
#include <mudlib.h>

int do_answer(string arg);
int ask_judge();
int ask_rejudge();

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
string str="";

varargs void mudchat(string msg, string who, object ob);

varargs void drool(string msg, string who, object ob);

string *fuck = ({
      "fuck","FUCK","ƨ��","����","������","�����",
        "����","����","ɵB","ɵb","ɵX","ɵx",
        "��Ѿ","Ѿͦ","�����","ȥ����","����","��Ů",
        "X��","����","����","ɵ��","����","����","�Ҳ�"
        });

varargs void alldrool(string msg, string who, object ob);

string *allfuck = ({
      "fuck","FUCK","ƨ","��","��","��","��","��","үү",
        "��","��","��","ɵ","Ѿ","��","����","����",
        "����","�׳�","��","��","�","cao","Ѩ","ֵǮ",
        "С��","��","����","��","��","��","��","��",
        "shit","SHIT","��","��","����","����","��"
        });

//��������ų���������һ�� emote ȫ��¼�ˣ��д�����
string *except = ({
      "��Ц","����","����","���","����","ƨ��","�ɻ�","�ɹ�",
"ɵ��","�ɲ�","��","��Ц","Ѩ��","����","ɵЦ","�޵�����","��޳ɵ","˿����",
"��ȥ�ĵ���","����","���ֶ�","ɵڶ","����","ɵ��","����","�ô���","���̵���"
        });

void create()
{
        set_name("�����˷���", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
        set("shen_type", 0);

        set("gender", "����");
        set("age", 20);
        set("long", "����һ��ר�����л����˵ķ��١�\n");
        set_skill("dodge", 1000);
        set("max_qi", 10000);
        set("qi", 10000);
        set("max_jing", 10000);
        set("jing", 10000);

        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name": "�㻹�����й��򰡣�",
                "rumors": "��˵���Ǹ������ˣ��ٺ٣�����ؿ�����������ѽ��",
                "here": "�����Ƿ�ͥ��û�²�׼������",
                "����": (: ask_judge :),
                "��Ѷ": (: ask_judge :),
                "����": (: ask_rejudge :),
        ]) );
        
        remove_call_out("tohtml");
        setup();
        if( clonep() ){
        call_out("tohtml", 0);
                CHANNEL_D->register_relay_channel("chat");
                CHANNEL_D->register_relay_channel("rumor");
                CHANNEL_D->register_relay_channel("party");             
        }
}

void init()
{
        object ob = this_player();
        add_action("do_answer", "answer");
        add_action("do_answer", "huida");
        ob->set_temp("robot_judge", -1);
        if (!wiz_level(ob) && !ob->is_busy()) ob->start_busy(15);
        call_out("ok", 30, ob);
}

void ok(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->delete_temp("robot_judge");
        if (userp(ob) && !wiz_level(ob)) {
            command("say " + ob->name(1) + "���ڽ�����Ѷ���κ�ʱ��Կ���Ҫ�����С�");
            }
        tell_object(ob, "����̧��ͷ���˿��㣬ʾ������Կ�ʼ�ˡ�\n");
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("$N��ɥ�ط��ֻ����˷��ٸ����������ս����\n", ob);
}

void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say("�����˷�����Ц��˵�������޵в����棡\n");
        command("hehe");
}

void die()
{
        unconcious();
}

int do_answer(string arg)
{
        object ob = this_player();

        if (!arg) return 0;
        if (ob->query_temp("robot_judge") != 1) return 0;
        ans = ob->query_temp("answer");
        if (arg==ans) {
                tell_object(ob, "�����˷��ٵ��˵�ͷ��˵����OK����������ˡ�\n");
                command("say ��ͥ�������У�" + ob->name(1) + "���ػ�����һ������ط�֤�ݲ��㣬��" + ob->name(1) + "�����ͥ�ͷš�");
                ob->delete_temp("robot_judge");
                ob->delete_temp("answer");
                if (ob->query("lastroom") && ob->query("lastroom") != base_name(environment())) ob->move(ob->query("lastroom"));
                else if (ob->query("enter_wuguan")) ob->move("/d/wuguan/dayuan");
                else ob->move("/d/city/wumiao");
        }
        else {
                tell_object(ob, "�����˷���̾�˿���������ô�򵥶��𲻶ԣ�����һ�������ˣ�\n");
                command("say ��ͥ�������У�" + ob->name(1) + "��" + ob->query("gender") + "��" + chinese_number(ob->query("age")) + "�꣬����������������ʮ���������������������в����������ߡ�");
                ob->set_temp("robot_judge", 2);
        }
        return 1;
}

void test_robot(object ob)
{
        int temp, line, ltemp, c, cl, len;
        ans="";
        str="";
        tell_object(ob, "�����˷������������ӣ�˵���������������п�ʼ����ش�һ��С���⡣��\n");
        ob->set_temp("robot_judge", 1);
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
        ob->set_temp("answer",ans);
        tell_object(ob, "����answer����ش���������������ʲô��\n");
        tell_object(ob, str);
}

int ask_judge()
{
        object ob = this_player();
        int temp;
                if ( (int)ob->query_condition("jyrobot") > 0) {
                        write("���һ�ᣬ�㻹�ڹ�Ѻʱ���С�\n");
                        return 1;
                }
        if (temp = ob->query_temp("robot_judge")) {
                if (temp < 0) {
                        write("���һ�ᣬ�������ڿ�������ϡ�\n");
                        return 1;
                }
                if (temp > 1) {
                        write("���Ѿ������й��ˣ����в��������ߣ�\n");
                        return 1;
                }
                else {
                        write("�����������У�\n");
                        return 1;
                }
        }
        command("say ��ͥ��������" + ob->name(1) + "����Ϊ������һ����");
        test_robot(ob);
        return 1;
}

int ask_rejudge()
{
        object ob = this_player();
        int temp;
        if (temp = ob->query_temp("robot_judge") < 2) {
                if (temp == 1) {
                        write("�����������У�\n");
                        return 1;
                }
                else {
                        write("�㻹û�����й�������ʲô����\n");
                        return 1;
                }
        }
        command("say ��ͥ��������" + ob->name(1) + "����Ϊ������һ�������߰���");
        test_robot(ob);
        return 1;
}

void relay_channel(object ob, string channel, string msg)
{
        string who;
        if( !userp(ob) ) return;
        if( !((channel == "chat") || (channel == "rumor")|| (channel == "party")) ) return;
        who = ob->query("name");
        if( ob==this_object() ) return;
        drool(msg, who, ob);
        alldrool(msg,who,ob);
        if (channel =="chat") mudchat(msg,who,ob);
}

//Add By Look, about ת��
varargs void mudchat(string msg, string who, object obj)
{
        mapping mem;
        string *ob;
        object me = this_player();
        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        if(!wiz_level(me))
  //      write_file("/log/html/MUDCHAT", sprintf("�����ġ�%s(%s)��%s\n", me->query("name"),capitalize(me->query("id")),msg));
        return;
}

//��¼�໰���ر�Ƶ��
varargs void drool(string msg, string who, object obj)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, flag = 0;

        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        msg = replace_string(msg, " ", "");
        for(i=0;i<sizeof(fuck);i++){
                if (strsrch(msg, fuck[i]) >= 0) flag=1;
        }
        if( flag )
        {       if (wiz_level(me)<3){
                message("channel:chat", HIC "��ͨ�桿" + who + "�ڹ���Ƶ�������к��в����Դʣ���������ر����н�̸Ƶ���Ĵ�����\n" NOR,users());
//                write_file( "/log/FUCK", sprintf("%s %s(%s)˵�໰��"HIM" %s "NOR"���ر�ȫ��Ƶ����\n", ctime(time())[4..19],
//                me->query("name"),me->query("id"),msg));
                obj->set("chblk_on", 1);
                obj->set("chblk_party", 1);
                return;
                }
        }
        return;
}

//��¼ȫ�������ɵĻ��������ر�Ƶ����������ʦ���� ��Ȼ��Ǻܶ࣬�ܱ� log ȫ���õ�
varargs void alldrool(string msg, string who, object obj)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, j,flag = 0;
        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        for(i=0;i<sizeof(allfuck);i++)
        for(j=0;j<sizeof(except);j++){
                if (strsrch(msg, allfuck[i]) >= 0 )     flag=1;
                if (strsrch(msg, except[j]) >= 0) flag =0;
                                }
        if( flag )
        {
//                write_file( "/log/ALLFUCK", sprintf("%s %s(%s)˵��"HIM" %s "NOR"\n", ctime(time())[4..19],
//                me->query("name"),me->query("id"),msg));
                return;
        }
        return;
}


