// linzhennan.c ������
// modified by Jay 4/7/96

#include <ansi.h>
int potential_lv(int exp);
inherit NPC;
//#define CART_PATH "cart"
//string do_quest();

string* dart_area=({"/d/beijing/dangpu","/d/beijing/qianzhua","/d/city/qianzhuang",
"/d/foshan/dangpu","/d/xiangyang/dangpu","/d/suzhou/dangpu","/d/cangzhou/bank","/d/city4/qianzhuang","/d/chengdu/qianzhuang","/d/jinling/qianzhuang","/d/jinling/dangpu","/d/tanggu/dangpu","/d/kunming/dangpu","/d/jingzhou/qianzhuang"});
string* dart_short=({"��������","����Ǯׯ","����Ǯׯ","Ӣ�۵䵱","��������","���ݱ��ͼ�","������","���Ǯׯ","����Ǯׯ","�¼�Ǯׯ","������","�򸣵䵱","��������","����Ǯׯ"});
string* dart_id=({"jia laoliu","qian laoben","qian yankai","lao chaofeng","qiu hang",
"wang heji","jiang tiaohou","tie suanpan","ma youcai","banker","xia tian","yin laoban","liu tong","qian defa"});
string* dart_name=({"������","Ǯ�ϱ�","Ǯ�ۿ�","�ϳ���","��","���ϼ�","������","������","���в�","���ز�","����","���ϰ�","��ͨ","Ǯ�÷�"});

string do_job();
string do_give();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
        set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "����");
        set("age", 45);
        set("title", "�����ھ�����ͷ");
        set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);
        set_skill("force", 40);
        set("per",19);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("inquiry", ([
                "������լ" : "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
                "�����ھ�" : (: ask_fuwei :),
                "Զͼ��" : (: ask_yuantu :),
                "��Զͼ" : "�����ϴ�ŭ��С������ôû��ò��ֱ���������䣡\n",
                "��а����" : (: ask_pixie:),
                "ͭǮ" : (: ask_tong:),
                "ͭ��" : (: ask_tong:),
                "����" : (: do_job :),
                "��"   : (: do_job :),
                "����" : (: do_job :),
                "job"  : (: do_job :),
                "����" : (: do_give :),
                "over" : (: do_give :),
        ]) );
        set_temp("no_get",1);
        set_temp("no_kill",1);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 400);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_fuwei()
{
        say("��������ҫ��˵�������ּ��������ڣ�һ����������Զͼ�����괳�µ���������\n"
        "�����������ּҼҴ������ն����㺬��������н��յľ��棬��Ϊ����������\n"
        "һָ�Ĵ��ھ֡��������ᵽ�������ھ֡����֣�˭��Ҫ�����Ĵָ��˵һ������\n"
        "�ø����������磡��������������\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
}

int ask_yuantu()
{
        if ((int)this_player()->query_temp("marks/��1")) {
                say("�����Ͽ�һ���̶���˵����Զͼ�����ҵ��游�������ھ�����һ�ִ���ġ�����\n"
                "�游����ʮ��·��а���������ھ֣������Ǵ��ڵ��޵��֡���ʱ�׵���Ӣ�ۼ�\n"
                "��̫�����磬Ҳ��ȥ�����������յģ�����������������ʦ������������֮ʱ\n"
                "��������а���������˼��С�\n");
                this_player()->set_temp("marks/��2", 1);
                return 1;
        }
        else {
                say("������˵����Զͼ�����ҵ��游��\n");
                return 1;
        }
}

int ask_pixie()
{
        int p1, p2, p3, p4;
        if ((int)this_player()->query("passwd")) {
                say("�����ϲ��õ�˵�����Ҳ��Ƕ������������ҵĽ����������档\n");
        }
        else if ((int)this_player()->query_temp("marks/��2")) {
                say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ��ˣ����µĹ�������\n"
                "��֪��ϸ����ʵ���������档��\n");
                write("�����϶�һ�٣����Ŷ������˵������ȥ��ǰ�������Ҹ�����");
                p1=random(4)+1;
                p2=random(4)+1;
                p3=random(4)+1;
                p4=random(4)+1;
                this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
                write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
                        "��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
                write("��\nͭǮ����һֱδ�����а��ء�\n");
        }
        else {
                message("vision", HIY "�����ϲ�Ȼ��ŭ���ȵ�����Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ�\n"
                        NOR, environment(), this_object() );
                kill_ob(this_player());
        }
        this_player()->delete_temp("marks/��1");
        this_player()->delete_temp("marks/��2");
        return 1;
}

int ask_tong()
{
        int p, p1, p2, p3, p4;
        if (!(p=(int)this_player()->query("passwd"))) {
                say("������һ����Ц�����ӣ�˵����ô�쵽��һ���˵���ҪǮ��\n");
        }
        else {
                write("�����ϵ���˵������ȥ��ǰ�������Ҹ�����");
                p1=(int)p/1000;
                p2=(int)(p-p1*1000)/100;
                p3=(int)(p-p1*1000-p2*100)/10;
                p4=(int)(p-p1*1000-p2*100-p3*10);
                write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
                        "��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
                write("��\nͭǮ����һֱδ�����а��ء�\n");
        }
        return 1;
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return time;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

    if ( ob->query_temp("in_dart"))
       return "�㲻�ǲ�Ҫ��������\n";
    if (environment(ob)->query("short")!="����")
       return "������ʲô�ط���\n";
    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "�����û�������ɡ�\n";
    if ((int)ob->query_condition("menpai_busy"))  
       return "�����Ǽ�Σ�չ������ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

    if ( (int)ob->query("combat_exp") < 50000 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�ƺ�û����������\n";

    if ( (int)ob->query_skill("force",1) < 100 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�Ļ����������㣡\n";

    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->apply_condition("dart_limit", 30);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/fuzhou/biaojuzt");
    command("nod");
    message_vision(CYN "������ƽ������˳�����\n" NOR,ob); 
    return "�����������͵�"+dart_short[n]+"��"+dart_name[n]+"���С�\n";
    
}

string do_give()
{
int bonus;
  object ob;
// int max_pot;

  ob=this_player();
//   max_pot=(int)this_player()->query("max_pot");

  if ( !ob->query_temp("in_dart"))
    return "��û�������ڰ���\n";

  if (environment(ob)->query("short")!="����")
       return "������ʲô�ط���\n";

  if ( !ob->query_temp("over_dart") )
    return "�ڳ�û���͵���ͷ��Ī���������ˣ���\n";

  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  

if (ob->query("combat_exp") < 1000000)
{
    ob->add("combat_exp",random(600)+380);
    ob->add("potential",random(500)+380);                    
}
else if (ob->query("combat_exp") > 5000000)
{
    ob->add("combat_exp",random(600)+380);
    ob->add("potential",random(500)+380);                    
}
else {
    ob->add("combat_exp",random(700)+380);
    ob->add("potential",random(500)+380);                    
}
        
        bonus = (int)ob->query("potential");
        bonus = bonus - (int)ob->query("learned_points");
        bonus = bonus + random(50)+100;
        if ( bonus > potential_lv((int)ob->query("combat_exp")) )
        bonus = potential_lv((int)ob->query("combat_exp"));
        bonus += (int)ob->query("learned_points");
//        ob->set("potential", bonus );                    
//    ob->add("potential",random(50)+100);
// ob->set("potential",max_pot);
      MONEY_D->pay_player(ob, random(30000)+5000);
  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"��Ȼ�Ƕ���֮�ţ�\n";
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}

