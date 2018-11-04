//guinu.c ��ū

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ū", ({ "guinu", "slave" }) );
        set("gender", "����" );
	set("title", "����Ժ�ܹ�");
        set("age", 32);
        set("long", 
	    "��������Ժ����������µģ�û��������Ժ�Ͳ����н���ķ��١�"
	    "������Ҳ�ɾ��˱���Ϊ潵Ļ��¡����������������ˣ������ǡ�\n");
          set("str", 55);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("shen_type", -1);

        set_skill("unarmed", 60);
	set_skill("force", 20);
        set_skill("dodge", 55);

        set("combat_exp", 95000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "��Ҳ��֪����ԭ����ʲô��",
            "ΤС��" : "���������ϰ���Ķ��ӡ�",
            "����Ժ" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "here" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "����" : "�ǿɲ��С���������Ĺ�����ҡǮ����������ӱ��ظ���Ǯ��",
	    "����" : "�ǿɲ��С���������Ĺ�����ҡǮ����������ӱ��ظ���Ǯ��",
            "����" : "������ǹ�����ⶼ��������ʲôҤ�ӡ�",
       ]) );

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
	"��ū����˵�����͹٣���ҪȱǮ���Ͱ������ã�Ů��ʲô�������������ɡ�\n",
	"��ū����˵������֮ǰ����������������ϰ��˭Ư��˭���������ü�Ǯ��\n",
	}) );
        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell","sell");
}

void greeting(object me)
{
    object * ob;
    int found,i;
    
    found = 0;
    
    if (me->query("hooker")) {
	command("say �ð���"+me->name() + "���һ�����Ҫ�ӵ�����أ����ֻ����ˣ�");
	command("say ��Ҫ�����Ҵ������ȣ�");
	return;
    }
    if (me->query("gender")!="����") {
      ob = all_inventory(environment());
      for(i=sizeof(ob)-1; (i>=0) && !found; i--) {
      if( !userp(ob[i]) ) continue;
      if (ob[i]->query("hooker")) {
         found = 1;
         command ("say "+ob[i]->name() + "�������������˻�����ӭ�ӣ� ");
         command ("kick " + ob[i]->query("id"));
      }
      }   
    }
    return ;
}
int do_sell(string arg)
{
    object ob;
    int value, per, extra = 1;

    string* name1s = ({
       "С", "��", "��", "��", "��", "��" });
    string* name2s = ({
       "��", "��", "��", "��", "��", "��", "Ҷ", "��", "��" });
    string* name3s = ({
       "���", "����", "����" });
    string nick;
    
    if (!arg || !(ob = present(arg, this_player())))
       return notify_fail("��Ҫ��˭��\n");
       
    if (!ob->is_character())
       return notify_fail("�������������ȥ��\n");
              
    if (!userp(ob))
       return notify_fail("����ֻ���������Ů��\n");
       
    if (ob->query("gender")!="Ů��")
       return notify_fail("��ԺĿǰ�������мˡ�\n");
      
    if (ob->query("hooker"))
       return notify_fail("���Ѿ�����������Ժ�����ˣ��㲻�������ˡ�\n");
      if ((value = ob->query("combat_exp")) < 350000)
       return notify_fail("�����Ǹ������أ��ҿ�û���������\n");
       

    per = ob->query("per")*100;
    if( ob->query_temp("top_girl") ) {
	extra = 10 ;
	per = ob->query("per")*1000;
	command("admire "+this_player()->query("id"));
	command("say ��εĻ�ɫ������С��治����\n");
    }

    message_vision("$N��"+ ob->name()+"����������Ժ��\n", this_player());
    MONEY_D->pay_player(this_player(), (per+value)*extra);
    this_player()->set("shen",this_player()->query("shen")-(value/100));
    this_player()->set("sell_woman/" + ob->query("id"), 1);

    ob->move(this_object());
    nick = name1s[random(sizeof(name1s))] + name2s[random(sizeof(name2s))]
           + name3s[random(sizeof(name3s))];
    if (ob->query("age")<18)       
        ob->set("title","����Ժ����");
    else if (ob->query("age")<25)
        ob->set("title","����Ժͷ��");
    else if (ob->query("age")<45)
        ob->set("title","����Ժ�ʺ�");
    else ob->set("title","����Ժ��ʦ");
    if( ob->query_temp("top_girl") ) {
	ob->set("title",HIR"����Ժ����"NOR);
	ob->delete_temp("top_girl");
    }
    ob->set("nickname",nick);
    command ("chat ��������Ժ�����ˡ�"+nick+ "��"+ob->name()+"����ӭ��λ��ү��ˣ�");
    ob->set("hooker",1); 
    return 1;
}
 
int accept_object(object me, object obj)
{
  if(obj->query("money_id")) {
    if(me->query("hooker")) {
        if (obj->value()>= me->query("combat_exp")*2)  {  
        command ("say �ðɣ��˸���־����Ҫ������Ҳ����ǿ���Ҹ����˼Ҽ��˰ɡ����Ǵ�һ�����ġ�");
        command ("cry "+me->query("id"));
        me->set("title",me->query("family/family_name")+"��"+
                chinese_number(me->query("family/generation"))+
                "������");
        command("bye "+me->query("id"));
        me->delete("hooker");
        return 1;
        }
        else {
        command("say лл"+me->query("nickname")+"��Ǯ��");
        command("bow "+ me->query("id"));
        return 1;
        }
    }
    else {
        command("say лл��Ǯ��");
        command("bow "+ me->query("id"));
        return 1;
    }
  }
  else return 0;
} 

