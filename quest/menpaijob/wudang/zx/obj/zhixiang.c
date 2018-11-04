//Cracked by Roath
// zhixiang.c ������� 
// Marz@XKX, 11/11/96
// xQin 04/01

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();
void greeting(object);
int do_say(string);
//int do_kill(string);

void create()
{
        set_name("�������", ({ "zhixiang daozhang", "zhixiang", "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("nickname", "�������");
        set("long",
                "�����ǳ����ʦ�����顣\n"
                "����ʮ���ְ꣬λ�������������������𣬼������Ǯ��\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 18000);
        set("max_jing", 18850);
        set("neili", 122500);
        set("max_neili", 12500);
set_temp("no_kill",1);
set("no_get",1);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("score", 6000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 160);
        set_skill("tiyunzong", 160);
        set_skill("strike", 180);
        set_skill("taiji-quan",180);
        set_skill("parry", 160);
        set_skill("sword", 150);
        set_skill("literate", 150);
        set_skill("taoism", 150);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry", 
                ([
                        "���" : "������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��\n",
                        "����" : "���㣿ͯ���޼ɣ�ͯ���޼ɣ�Ҫ˵������ǣ�\n",
                        "����" : "���õ���������Ӳ��ϣ�����Ϊ���䵱���Ӻ�ɽ����ͼ�ʱ���\n",
                        "�Ϸ���" : "�Ϸ��׾���������������Ǯ�������幤��\n",
                        "����" : "�������������������Ǯ�������幤��\n",
                        "����" : "�䵱������ɽ�Ÿ�����\n",
                        "����" : "�䵱���־������湬��\n",
                        "����" : "���Ͼ��Ǻ��ɺ���أ���ÿ�춼Ҫ����ȥ������\n",
                        "job" : (: ask_job :),
                        "����" : (: ask_job :),
                        "��ľ" : (: ask_job :),
                        "����" : "������ÿ�춼��Ҫ��ȥ�������������������Щ�������Ǹ��á�\n",
                        "�ɻ�" : "������ÿ�춼��Ҫ��ȥ�������������������Щ�������Ǹ��á�\n",
                ]));
                                
        set("wanted", ({ HIR"��������"NOR }));

        set("chat_chance", 5);
        set("chat_msg", ({
                "����˵����������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��\n",
                "����˵�������ɺ���ض����������ĺò��ϡ�\n",
                "����˵������������Ǵ������￳��������\n",
                "����˵�����䵱�����ֺͰ��ֶ����˼������ˣ���û������ͨ����\n",
                "����˵����������ʱ��Ҫ���С�ģ����ɳ������ĵ�ʿ����Щ����ȥ�޻ء�\n",
        }) );

        setup();
      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void init()
{
        object me = this_player();
        
        ::init();

//        add_action("do_kill", "kill");

}

string ask_job()
{
        object ob;
object killer;
int k;
        string what;
        string *wanted;

        ob = this_player();

        if ( ob->query("job/supervisor") )
        {
                command("say ���һ�ݻ����û����������ڶ��ݣ�");

                if ( ob->query("job/supervisor") == "�������") 
                {
                add_action("do_say", "say");
                return ("�����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�");
                }
                
                return ("�����ɲ��ˣ�����ֱ��ȥ����"+ob->query("job/supervisor"));    
        }

        if ((int)ob->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), ob);
                return ("��ȥ������°�!");
            }

//        if (query_temp("stock") > 10)
//                return ("�������ˣ�����Ļ���Ҷ��������ˡ�");

//        add_temp("stock", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("job/supervisor", "�������");
        ob->set("job/object", what);
        ob->set("job/description", what);
        ob->set("job/wage", 3);
        ob->set_temp("apply/short", 
                ({ HIW"�䵱��ľ��"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
                                

//if (1)
if (random(40)==1)
{
        message_vision("��˵�������в�����ݵ��������������䵱���ƣ�С��һ�㡣\n", ob);
killer=new(__DIR__"killer",1);
if ((int)ob->query_skill("force",1) > 10)
{
k=(int)ob->query_skill("force",1);
}
else k=10;
      killer->move("/quest/menpaijob/wudang/zx/pine_forest"+(random(9)+1));
        killer->set("combat_exp",ob->query("combat_exp"));
        killer->set("qi", ob->query("max_qi"));
        killer->set("eff_qi", ob->query("max_qi"));
        killer->set("max_qi", ob->query("max_qi"));
        killer->set("jing", ob->query("max_jing"));
        killer->set("eff_jing", ob->query("max_jing"));
        killer->set("max_jing", ob->query("max_jing"));
        killer->set("neili", ob->query("max_neili"));
        killer->set("max_neili", ob->query("max_neili"));
        killer->set_skill("xue-dao", k);
        killer->set_skill("unarmed",k);
        killer->set_skill("xianglong-zhang",k);
        killer->set_skill("dodge", k);
        killer->set_skill("blade", k);
        killer->set_skill("parry", k);
        killer->set_skill("dashou-yin", k);
        killer->set_skill("shenkong-xing", k);
        killer->set_skill("longxiang", k);
        killer->set_skill("huntian-qigong", k);
}
        message_vision("����������˶�$N˵�����������ã�������ȱ���֣�\n", ob);
        return ("����Ҫ"+ what +"�����ã���ȥ���ҿ�Щ���ɣ�\n");
}

int accept_object(object who, object ob)
{

        object obn, wage;       
        int i, j, k,l;
        int exp,pot;
        string *wanted;

                if (ob->query("money_id") )     
        {
                if ((string)(who->query("family/family_name")) == "�䵱��") 
                        tell_object(who, 
                        "����������̾�����䵱ɽ���ʢ��ȫ�����������������𰡣�\n");
                else  
                        tell_object(who, 
                        "����������̾�����䵱ɽ���ʢ��ȫ����������������Ͱ���\n");

                return 1;
        } else if (  ((string)who->query("job/supervisor") == "�������")
                        && (string)who->query("job/object") == (string)ob->query("name") )   
        {
                i = (int)who->query("wdjob/wage");
                l = (int)who->query("wdjob/wage");
                if (i < 0 ) i = 2;
                if (i > 800) i=800;
                wage = new("/clone/money/silver");
k=random(i);
                if (k < 0 ) k = 2;
if (k>80)k=80;
                wage->set_amount(k);
                wage->move(who);

                command("say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
                command("thumb " + who->query("id"));
if (random(10)<2)
{
               message_vision("$Nͨ��Ϊ�䵱���£�����˶��䵱�����ġ�\n", who);
               who->add("guarded",1);
}
                message_vision("���������$N"+chinese_number(k)+"��������Ϊ�������ꡣ\n", who);
                j=random(i);
if ((string)(who->query("family/family_name")) == "�䵱��") 
{
if ((20+j) < 50)
exp =90;
if ((20+j) > 200)
exp =300;
if (exp <90 ) exp=90;
if (exp >350) exp=350;
                who->add("combat_exp", exp);
                who->add("potential", exp*2/3);
                message_vision("$N�ľ������"+chinese_number(exp)+"�㡣\n", who);
                message_vision("$N��Ǳ�ܼ���"+chinese_number(exp*2/3)+"�㡣\n", who);
                message_vision("$N�䵱������������"+chinese_number(l)+"���ˡ�\n", who);
}
                who->delete_temp("jobwd");
                who->delete_temp("apply/short");
                who->add("wdjob/wage", 1);
                who->delete("job/supervisor");
                who->delete("job/description");
                who->delete("job/wage");
                who->delete("job/object");
                who->start_busy(4);
                return 1;
        } else if( (int)member_array((string)ob->query("name"), (string *)query("wanted")) != -1 )    
        {
                
                message_vision("����������˶�$N˵�����������ã�������������Ҫ�ģ�\n", who);

    
                if ( who->query("family/family_name") == "�䵱��"  )
                {
                        if ( random(2) ) 
                        {
                                tell_object(who, "�������������һ֦������ȥ����ɡ�\n");
                                who->add("wudang/offerring", -1-random(3));
                                obn = new(__DIR__"incense");
                                obn->move(who);
                        }
                        
                }

                who->delete_temp("jobwd");
                command("say �������ԸΪ�䵱Ч�����պ�س��䵱������");
                command("thumb " + who->query("id"));
                
                return 1;
        }


        return 0;
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( (string)arg != "�ɲ���") return 0;

    if ( who->query("job/supervisor") != ob->query("name")) return 0;

    message_vision("$N����˵�����������ɵĻ��Ҹɲ��ˡ�\n", who);
    command("pat "+ who->query("id"));
    command("say û��ϵ���´˺úøɣ�");

who->apply_condition("menpai_busy",2+random(4));
                who->delete_temp("jobwd");
    who->delete_temp("apply/short");
    who->delete("job/supervisor");
    who->delete("job/description");
    who->delete("job/wage");
    who->delete("job/object");

    return 1;
}

