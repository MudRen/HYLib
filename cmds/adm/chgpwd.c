// chgpwd.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        if (!arg)   return notify_fail("��Ҫ��˭������?\n");
        ob=FINGER_D->acquire_login_ob(arg);
        if (!ob)   return notify_fail("û����λ��ҡ�\n");
        if( me!=this_player(1)
        && wiz_level(me) <= wiz_level(SECURITY_D->get_status(arg)) )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
if (arg=="hxsd" ||
arg=="bbs" ||
arg=="wuyou" ||
arg=="yaodm" ||
arg=="hongtian" ||
arg=="meier" ||
arg=="yesno" ||
arg=="cash" ||
arg=="lywin" ||
arg=="ying" ||
arg=="yanyan" ||
arg=="zzz" 
)
return notify_fail("���ܸ�WIZ���롣\n");
        printf("������%s Ȩ�޵ȼ���%s\n",ob->query("name"),SECURITY_D->get_status(arg));
        write("�������µ����룺");
        input_to("get_new_pass", 1, ob );
        return 1;
}
private void get_new_pass(string pass, object ob)
{
    if( strlen(pass)<5 ) {
        write("����ĳ�������Ҫ����ַ������������룺\n");
        write("�������µ����룺");
        input_to("get_new_pass", 1, ob );
        return;
    }
        write("\n��������һ���µ����룺");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}
private void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("password", new_pass) ) {
                write("������ʧ�ܣ�\n");
                return;
        }
        ob->save();
        write("�������ɹ���\n");
}
int help(object me)
{
        write(@HELP
ָ���ʽ : chgpwd <���id>
 
���ָ������޸���ҵ��������롣
 
HELP
    );
    return 1;
}

