// /NPC shinu.c

#include <ansi.h>
string ask_tea(object ob);
inherit NPC;
void create()
{
       set_name("����С��", ({ "luyi xiaotong", "xiaotong", "luyi"}));
       set("long","������ü��Ŀ�㣬�Ǹ�ר���̲��С�ס�\n");
       set("title","�������ͯ");
       set("gender", "����");
       set("age", 15);
       set("shen_type",1);
       set("attitude", "peaceful");
  
       set("str", 14);
       set("int", 20);
       set("con", 25);
       set("dex", 20);
       set("per", 20);

       set("qi", 300);
       set("max_qi", 300);
       set("jing", 200);
       set("max_jing", 200);
       set("eff_jingli",200);

       set("combat_exp",10000);
       set("inquiry", ([
		   "��" : (: ask_tea :),
       ]));

       setup();
       carry_object("/clone/misc/cloth")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("����С��Ц������˵������λ" + RANK_D->query_respect(ob)
             + "���ˣ�" + "����͸����ݲ衣\n");
}

string ask_tea(object ob)
{ 
       object obj;
       if ((this_player()->query("water")*10/this_player()->max_water_capacity())>8)
            return "����ô�ȱ��˻���Ҫ��";
       if ( present("longjin cha", this_player()))
            return "���Ⱥ������Ҹ������˵�ɡ�";
       if ( present("longjin cha",  environment(ob)) )
            return "�ǲ��������Ⱥ�������˵��";
       obj=new("/d/jqg/obj/longjin");
       obj->move(this_player());
            return "�Ɑ������������������Ӵ��";
}
