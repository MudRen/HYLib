                    inherit NPC;

void destroying(object, object);

void create()
{
        set_name("����", ({ "juyou" }));
        set("long", 
                "����һ�����úܺÿ���С�������æ�Ž�һ��ջ���\n");
        set("title","Ѿ��");
        set("gender", "Ů��");
        set("age", 15);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 3000);
        set("shen_type", 1);
        setup();
        carry_object("/d/city/obj/pink_cloth")->wear();

}

int accept_object(object me, object obj)
{
object key;
        if ((string)obj->query("id")=="ye juhua") {
        message("vision",me->name()+"������һ��Ұ�ջ���\n",environment(me),
            ({me}));
        command("ah "+me->query("id"));
        command("say �벻����λ"+RANK_D->query_respect(me)+"Ҳ�Ǹ����ջ����ˡ�");
             key = new(__DIR__"obj/tyaoshi");
        key->move(me);
             message_vision("$n�ݸ�$Nһ��ͭԿ�ס�\n", me, this_object() );
        command("say �����Ҳû�����̾ջ��ա��Ҽ�С��뷿���������У������ȥ������");
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
