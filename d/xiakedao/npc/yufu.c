// yufu.c
// [С���� 1999/11/4]

inherit NPC;
void consider();
int accept_object(object me, object ob);

void create()
{
        set_name("���", ({ "yu fu","yu" }) );
        set("gender", "����" );
        set("age", 22);
        create_family("���͵�", 2, "����");
     set("inquiry", ([
                "���͵�" : "��ô������ȥ���ҵ�ʦ�������ҵ��ǵط���̫���ף�ֻ��ϧ�ҵĴ����ˡ���������\n",
]));
        setup();
}
int accept_object(object me, object ob)
{
        object ling1;
        object ling2;
        if (ob->query("money_id") && ob->value() >= 50000)
     tell_object(me, "���Ц��˵�����ðɣ���Ȼ����Ե�ˣ��Ҿ�������������ɡ�\n");
  else
   {
      tell_object(me,"���������ü��˵�������Ҳ���ҪǮ�ƣ���\n");
    return 0;
  }
//        return 1;

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        return 1;
}