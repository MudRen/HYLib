// caiyao.c ��ҩ����
#include <ansi.h>;
inherit NPC;

string ask_me();
int accept_object(object who, object ob);
void destroying(object me, object obj);

void create()
{
        set_name("��ҩ����", ({ "caiyao daozhang", "caiyao" }));
        set("long", 
                "�����䵱ɽ�Ĳ�ҩ������\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("taiji-jian", 20);
        set_skill("taoism", 20);

        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("�䵱��", 4, "����");
        set("inquiry", ([
                "�ŵ�" : (: ask_me :),
        ]));

        set("chat_chance", 7);
        set("chat_msg", ({
"��ҩ�����п���:�벻������ɽ�ﻹ��һ��������εĹŵ���\n",
"��ҩ����������Թ��:���Ǵ�ͷϺ����Ȼ��ҩ����Ū���ˣ���!���û�ȥ����һ�ѡ�\n",
        }) );


        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

int accept_object(object who, object ob)
{
         object me;
         object obzi;
         me=this_player();
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("��û�����������");
        if ((string)ob->query("id") == "yao chu"){
         command("say ����������Ҫ�ģ�Ϊ�˱������Ҿʹ��㵽һ����ĵط�ȥ��!\n");
         remove_call_out("destroying");
         call_out("destroying", 1, this_object(), ob);
         command("say �����������Ҳ�ҩ�õģ���Ҳһ������ȥ�ɣ�˵��������!\n");
         obzi=new("/d/wudang/obj/shengzi");
         obzi->move(me);
         me->move("/d/wudang/gudao1");
         return 1;
         }
        return 0;
}

string ask_me()
{
        return "Ϊ�˷�����ŵ���������ͷ�����ˣ��ɲ������׸�����!\n";
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
