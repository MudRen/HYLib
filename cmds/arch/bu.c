#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

    if( !str || str == "")
        return notify_fail("��Ҫ��˭ת��?\n");

    if ( !obj = present(str,environment(me)))
        return notify_fail("����û��"+str+"\n");
    
    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

//    if ( obj->query("zhuanshen"))
//        return notify_fail("�����Ѿ�ת������!\n");

//    if ( (int)obj->query("combat_exp") < 5000000)
//        return notify_fail("����û���ʸ�ת��!\n");


if (obj->query("str") <25)
{
obj->set("str",25);
message_vision(HIB"$N��������������ˣ�\n"NOR, obj);
}
if (obj->query("int") <25)
{
obj->set("int",25);
message_vision(HIC"$N���������������ˣ�\n"NOR, obj);
}
if (obj->query("con") <25)
{
obj->set("con",25);
message_vision(HIY"$N��������������ˣ�\n"NOR, obj);
}
if (obj->query("dex") <25)
{
obj->set("dex",25);
message_vision(HIG"$N�������������ˣ�\n"NOR, obj);
}
if (obj->query("kar") <30)
{
obj->set("kar",30);
message_vision(HIC"$N��������������ˣ�\n"NOR, obj);
}
if (obj->query("per") <30)
{
obj->set("per",30);
message_vision(HIB"$N��������ò�����ˣ�\n"NOR, obj);
}
if (obj->query_skill("unarmed",1)<250)
{
  obj->set_skill("unarmed",250);
message_vision(HIM"$N�Ļ����������ˣ�\n"NOR, obj);
}
if (obj->query_skill("parry",1)<250)
{
 obj->set_skill("parry",250);
message_vision(HIM"$N�Ļ����м������ˣ�\n"NOR, obj);
}
if (obj->query_skill("dodge",1)<250)
{
  obj->set_skill("dodge",250);
message_vision(HIM"$N�Ļ����Ṧ�����ˣ�\n"NOR, obj);

}
if (obj->query_skill("force",1)<250)
{
  obj->set_skill("force",250);
message_vision(HIM"$N�Ļ����ڹ������ˣ�\n"NOR, obj);
}
if (obj->query_skill("literate",1)<250)
{
  obj->set_skill("literate",250);
message_vision(HIM"$N�Ķ���д�������ˣ�\n"NOR, obj);
}
        obj->set("combat_exp", 2500000);
        obj->add("potential",500000);
        message_vision(HIR"$N�����2500000�����500000Ǳ��!\n"NOR, obj);
        obj->set("max_neili", 800);
        message_vision(HIR"$N�����800����������!\n"NOR, obj);

        obj->set("mud_age",400000);
        obj->save();
    write(HIR"��������!\n"NOR);

    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : zhuanshen <����>

���ô�ָ���Ϊ��ҽ���ת�������ת����
����Ϊ300K,Ǳ��Ϊ100K,�������Գ�����
(����50).18�꿪ʼ��ԭ���书ȫ����ʧ��
��ԭ�е��̵��ߣ��������������ȫ�����档
HELP
    );
    return 1;
}

