// cao
inherit NPC;
#include <ansi.h>

string ask_toy();
string ask_work();
string ask_workover();

void create()
{
        set_name("�๤", ({ "jian gong", "gong" }) );
        set("gender", "����" );
        set("age", 28);
        set("long", 
            "�����ǲ�ʯ���ļ๤����������һ˫ţͷ���ۿ����㡣\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "��ʯ" : "������ǲ�ʯ�����Ҿ�������ļ๤��",
            "ʯͷ" : "���ص�ʯͷ�㿴����ѽ��",
            "����" : (: ask_toy :),
            "����" : (: ask_work :),
            "����" : (: ask_workover :),
       ]) );

        setup();

        set("hammer_count", 4);
         set("chat_chance", 5);
         carry_object("/clone/cloth/cloth")->wear();
}
int accept_fight()
{
        command("say һ��ȥ��û������æ���أ��������Ĵ���ȥ��");
        return 0;
}

string ask_toy()
{
        object ob;
        
        if(present("hammer" , this_player()))
                return "�����ϲ������𣿻���Ҫ���ǲ��Ǵ��ĵ�������";
        if (query("hammer_count") < 1)
                return "��������ͷ��Ҳû�У����ٵȻ���ɣ�";
        add("hammer_count", -1);
        ob = new("/clone/weapon/hammer");
        ob->move(this_player());
        return "�๤˵����������ඣ���\n�๤������һ��������";
}

string ask_work()
{
        if(!this_player()->query("old_title"))
        {
                if ( !this_player()->query("old_title") )
                       this_player()->set("old_title",this_player()->query("title"));
//                this_player()->set("title",HIY"��ʯ��"NOR);
                this_player()->set_temp("stonework",0);
                return "����ȥ���������벻����Ǯ�ˣ�";
        }
        return RANK_D->query_respect(this_player()) + 
        "�����й��������ѵ����벻���ˣ�����ͽ����ɣ�";
}
string ask_workover()
{
        object me, silver;
        me = this_player();
          if(!me->query("old_title"))
                return "������ʲô��˼�������ʲôѽ��";
        if(me->query_temp("stonework")<6)
        {
               me->set("title",this_player()->query("old_title"));
               me->delete_temp("stonework");
               me->delete("old_title");
               command("nod " + this_player()->query("id"));
               return "��ȥ���ɣ�������ˣ����������е����ϧ����������һ����������\n";
        }
        else 
        {
        this_player()->set("title",this_player()->query("old_title"));
        this_player()->delete_temp("stonework");
        this_player()->delete("old_title");
        silver = new("/clone/money/silver");
        silver->set_amount(random(10)+1);
        silver->move(this_player());
        command("pat " + this_player()->query("id"));
        return "��������Թ�������ҵĺð��֣���Ը������˶��������������Ǿͺ��ˣ�������Ӧ�õģ�\n";
        }
}


